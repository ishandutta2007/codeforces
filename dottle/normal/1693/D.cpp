#include<bits/stdc++.h>
#define int long long
const int N=1005000,inf=1e9;
using namespace std;

struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    struct node{
    	int mn,sc;
    	node(){mn=sc=inf;}
    	node(int m,int s){mn=m,sc=s;}
    	node operator + (node b){
    		node ans;
    		ans.mn=min(mn,b.mn);
    		ans.sc=min({ans.mn==mn?sc:mn,ans.mn==b.mn?b.sc:b.mn});
    		return ans;
		}
	}s[N<<2];
    void pshup(int k){
        s[k]=s[ls]+s[rs];
    }
    void chg(int k,int l,int r,int x,int y,int z){
        if(l^r){
            if(x<=mid)chg(ls,l,mid,x,y,z);
            else chg(rs,mid+1,r,x,y,z);
            pshup(k);
        }else s[k]={y,z};
    }
    node qry(int k,int l,int r,int x,int y){
        if(y<l||x>r)return {inf,inf};
        if(y>=r&&x<=l)return s[k];
        return qry(ls,l,mid,x,y)+qry(rs,mid+1,r,x,y);
    }
}S,T;

int n,a[N],ia[N];
int res[N];
set<int> s;
vector<int> ny[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],ia[a[i]]=i,res[i]=n+1;
	int mn=n+1;
	for(int i=n;i>=1;i--){
		auto y=T.qry(1,1,n,a[i]+1,n);
		T.chg(1,1,n,a[i],i,inf);
		if(y.mn==inf)continue;
		ny[y.mn].push_back(i);
	}
	for(int i=n;i>=1;i--){
		auto it=s.lower_bound(a[i]);
		while(it!=s.end()){
			S.chg(1,1,n,*it,ia[*it],inf);
			it=s.erase(it);
		}
		s.insert(a[i]);
		for(auto x:ny[i]){
			auto y=S.qry(1,1,n,1,a[x]-1);
			res[x]=min(res[x],y.mn);
		}
	}
	memset(T.s,1,sizeof(T.s));
	memset(S.s,1,sizeof(S.s));
	s.clear();
	mn=n+1;
	for(int i=1;i<=n;i++)a[i]=n-a[i]+1,ia[a[i]]=i,ny[i].clear();
	for(int i=n;i>=1;i--){
		auto y=T.qry(1,1,n,a[i]+1,n);
		T.chg(1,1,n,a[i],i,inf);
		if(y.mn>=inf)continue;
		ny[y.mn].push_back(i);
	}
	for(int i=n;i>=1;i--){
		auto it=s.lower_bound(a[i]);
		while(it!=s.end()){
			S.chg(1,1,n,*it,ia[*it],inf);
			it=s.erase(it);
		}
		s.insert(a[i]);
		for(auto x:ny[i]){
			auto y=S.qry(1,1,n,1,a[x]-1);
			res[x]=min(res[x],y.mn);
		}
	}
	int sum=0;
	for(int i=n-1;i>=1;i--)res[i]=min(res[i],res[i+1]);
	for(int i=1;i<=n;i++)sum+=res[i]-i;
	cout<<sum<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}