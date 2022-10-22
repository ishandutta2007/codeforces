//Fight

// Problem: C. Game with Stones
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.ml/contest/1588/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
const int N=3e5+100;
const int inf=0x3f3f3f3f3f3f3f3f;
int t,n,a[N],sum[N];
struct SGTmx{
	int mx[N<<2],arr[N];
	void build(int x,int l,int r){
		if(l==r){
			mx[x]=arr[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		mx[x]=max(mx[lc],mx[rc]);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mx[x];
		if(r<ql||qr<l)return -inf;
		return max(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}MX;
struct SGTmn{
	int mn[N<<2],arr[N];
	void build(int x,int l,int r){
		if(l==r){
			mn[x]=arr[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		mn[x]=min(mn[lc],mn[rc]);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(r<ql||qr<l)return inf;
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}MN;
queue<int>q[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++)
			if(i&1)sum[i]=sum[i-1]+a[i];
			else sum[i]=sum[i-1]-a[i];
		for(int i=1;i<=n;i++)
			if(i&1)MN.arr[i]=sum[i],MX.arr[i]=-inf;
			else MN.arr[i]=inf,MX.arr[i]=sum[i];
		MX.build(1,1,n);MN.build(1,1,n);
		map<int,int>id;int tot=0;
		int ans=0;
		for(int i=n;~i;i--){
			if(!id[sum[i]])id[sum[i]]=++tot;
			int kk=id[sum[i]];
			while(q[kk].size()){
				if(MN.qry(1,1,n,i+1,q[kk].front())<sum[i])
					q[kk].pop();
				else if(MX.qry(1,1,n,i+1,q[kk].front())>sum[i])
					q[kk].pop();
				else break;
			}
			ans+=q[kk].size();
			q[kk].push(i);
		}
		write(ans);pc('\n');
		for(int i=1;i<=tot;i++)while(q[i].size())q[i].pop();
	}
}