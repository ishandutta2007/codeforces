#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,q,pre[200010],nxt[200010],flag[200010],l[200010],r[200010],x[200010],id[200010];
int minv[800010],tag[800010],mx[800010];

inline void build1(int o,int L,int R)
{
	minv[o]=INF;
	if(L<R){
		int mid=(L+R)/2;
		build1(o*2,L,mid);
		build1(o*2+1,mid+1,R);
	}
}

inline void build2(int o,int L,int R)
{
	mx[o]=1;tag[o]=1;
	if(L<R){
		int mid=(L+R)/2;
		build2(o*2,L,mid);
		build2(o*2+1,mid+1,R);
	}
}

inline void update1(int o,int L,int R,int X,int V)
{
	if(R<X||L>X) return;
	if(X<=L&&R<=X){
		minv[o]=V;
		return;
	}
	int mid=(L+R)/2;
	update1(o*2,L,mid,X,V);
	update1(o*2+1,mid+1,R,X,V);
	minv[o]=min(minv[o*2],minv[o*2+1]);
}

inline void pushdown2(int o)
{
	if(tag[o]==0){
		tag[o*2]=0;tag[o*2+1]=0;
		mx[o*2]=0;mx[o*2+1]=0;
		tag[o]=1;
	}
}

inline void update2(int o,int L,int R,int X,int Y)
{
	if(R<X||L>Y) return;
	if(X<=L&&R<=Y){
		tag[o]=0;mx[o]=0;
		return;
	}
	pushdown2(o);
	int mid=(L+R)/2;
	update2(o*2,L,mid,X,Y);
	update2(o*2+1,mid+1,R,X,Y);
	mx[o]=max(mx[o*2],mx[o*2+1]);
}

inline int query1(int o,int L,int R,int X,int Y)
{
	if(R<X||L>Y) return INF;
	if(X<=L&&R<=Y) return minv[o];
	int mid=(L+R)/2,res=INF;
	res=min(res,query1(o*2,L,mid,X,Y));
	res=min(res,query1(o*2+1,mid+1,R,X,Y));
	return res;
}

inline int query2(int o,int L,int R,int X)
{
	if(R<X||L>X) return 1;
	if(X<=L&&R<=X) return mx[o];
	pushdown2(o);
	int mid=(L+R)/2,res=1;
	res=min(res,query2(o*2,L,mid,X));
	res=min(res,query2(o*2+1,mid+1,R,X));
	return res;
}

inline int Find1(int o,int L,int R,int X,int Y)
{
	if(R<X||L>Y) return 0;
	if(X<=L&&R<=Y){
		if(mx[o]==0) return 0;
		if(L==R) return L;
		pushdown2(o);
		int mid=(L+R)/2;
		int res=Find1(o*2+1,mid+1,R,X,Y);
		if(res!=0) return res;
		res=Find1(o*2,L,mid,X,Y);
		return res;
	}
	pushdown2(o);
	int mid=(L+R)/2;
	int res=Find1(o*2+1,mid+1,R,X,Y);
	if(res!=0) return res;
	res=Find1(o*2,L,mid,X,Y);
	return res;
}

inline int Find2(int o,int L,int R,int X,int Y)
{
	if(R<X||L>Y) return n+1;
	if(X<=L&&R<=Y){
		if(mx[o]==0) return n+1;
		if(L==R) return L;
		pushdown2(o);
		int mid=(L+R)/2;
		int res=Find2(o*2,L,mid,X,Y);
		if(res!=n+1) return res;
		res=Find2(o*2+1,mid+1,R,X,Y);
		return res;
	}
	pushdown2(o);
	int mid=(L+R)/2;
	int res=Find2(o*2,L,mid,X,Y);
	if(res!=n+1) return res;
	res=Find2(o*2+1,mid+1,R,X,Y);
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>flag[i];
		if(flag[i]==0){
			cin>>l[i]>>r[i]>>x[i];
		}
		else{
			cin>>x[i];
		}
	}
	vector<pair<pair<int,int>,int> > v;
	for(int i=1;i<=q;i++) if(flag[i]==0&&x[i]==1) v.push_back(make_pair(make_pair(l[i],r[i]),i));
	if(!v.empty()){
		sort(v.begin(),v.end());
		for(int i=1;i<=v.size();i++) id[v[i-1].second]=i;
		build1(1,1,v.size());
	}
	build2(1,1,n);
	for(int i=1;i<=q;i++){
		if(flag[i]==0){
			if(x[i]==0){
				update2(1,1,n,l[i],r[i]);
			}
			else{
				update1(1,1,v.size(),id[i],r[i]);
			}
		}
		else{
			int u=query2(1,1,n,x[i]);
			if(u==0) cout<<"NO\n";
			else{
				if(v.empty()){
					cout<<"N/A\n";
					continue;
				}
				int L=x[i],R=x[i];
				if(x[i]>1) L=Find1(1,1,n,1,x[i]-1)+1;
				if(x[i]<n) R=Find2(1,1,n,x[i]+1,n)-1;
				int pos1=lower_bound(v.begin(),v.end(),make_pair(make_pair(L,0),0))-v.begin()+1;
				int pos2=lower_bound(v.begin(),v.end(),make_pair(make_pair(R+1,0),0))-v.begin();
				if(pos1>pos2){
					cout<<"N/A\n";
					continue;
				}
				int p=query1(1,1,v.size(),pos1,pos2);
				if(p<=R) cout<<"YES\n";
				else cout<<"N/A\n";
			}
		}
	}
	return 0;
}