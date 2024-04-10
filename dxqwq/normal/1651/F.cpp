// Problem: F. Tower Defense
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1651/problem/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n=read(),N;
#define round shitproblem
inline double round(double x){return (int)(x+0.5);}
int C[200003],R[200003],rk[200003],rt[200003];
double z[200003],lsh[200003],a[200003];
int sC[6000003],sR[6000003],ls[6000003],rs[6000003],cnt;
int build(int l,int r)
{
	if(l==r) return ++cnt;
	int mid=(l+r)>>1,L=build(l,mid),R=build(mid+1,r);
	++cnt,ls[cnt]=L,rs[cnt]=R;
	return cnt;
}
int update(int nl,int nr,int pos,int x,int tc,int tr)
{
	if(nl==nr)
	{
		++cnt,sC[cnt]=sC[x]+tc,sR[cnt]=sR[x]+tr;
		return cnt;
	}
	int mid=(nl+nr)>>1,y=++cnt;
	sC[y]=sC[x]+tc,sR[y]=sR[x]+tr;
	if(pos<=mid) rs[y]=rs[x],ls[y]=update(nl,mid,pos,ls[x],tc,tr);
	else ls[y]=ls[x],rs[y]=update(mid+1,nr,pos,rs[x],tc,tr);
	return y;
}
int query(int l,int r,int x,int y,double z)
{
	if(l==r) return min((int)round(z*(sR[y]-sR[x])),sC[y]-sC[x]);
	int mid=(l+r)>>1;
	if(lsh[mid]<=z) return sC[ls[y]]-sC[ls[x]]+query(mid+1,r,rs[x],rs[y],z);
	else return query(l,mid,ls[x],ls[y],z)+(int)round(z*(sR[rs[y]]-sR[rs[x]]));
}
struct Node{
    int l,r;
    mutable double val;
    Node(int a=-1,int b=-1,double c=0){l=a,r=b,val=c;}
    bool operator<(const Node&a)const{return l<a.l;}
};
set<Node> st;
set<Node>::iterator split(int pos)
{
    auto it=st.lower_bound(Node(pos));
    if (it!=st.end()&&it->l==pos) return it;
    --it;Node tmp=*it;st.erase(it);
    st.insert(Node(tmp.l,pos-1,tmp.val));
    return st.insert(Node(pos,tmp.r,tmp.val)).first; 
}
signed main()
{
	st.insert(Node(-1000000,0,0)),st.insert(Node(n+1,1000000,0));
	for(int i=1; i<=n; ++i) 
	{
		C[i]=read(),R[i]=read();
		st.insert(Node(i,i,-2e9)),lsh[i]=z[i]=1.0*C[i]/R[i];
	}
	sort(lsh+1,lsh+n+1),N=unique(lsh+1,lsh+n+1)-lsh-1;
	// for(int i=1; i<=N; ++i) printf("%.3lf\n",lsh[i]);
	for(int i=1; i<=n; ++i) rk[i]=lower_bound(lsh+1,lsh+N+1,z[i])-lsh;
	rt[0]=build(1,N);
	for(int i=1; i<=n; ++i) rt[i]=update(1,N,rk[i],rt[i-1],C[i],R[i]);
	int ans=0;
	for(int T=read(),t,x,y; T--;)
	{
		t=read(),x=read();
		for(auto i=++st.begin(); i!=st.end(); ++i)
		{
			if(i->l>n)
			{
				auto sdt=st.begin();
				++sdt;
				st.erase(sdt,i),
				st.insert(Node(1,n,t)),
				ans+=x;
				break;
			}
			y=query(1,N,rt[i->l-1],rt[i->r],t-i->val);
			if(y<x) x-=y;
			else
			{
				int tL=i->l,tR=i->r-1,res=i->r;
				while(tL<=tR)
				{
					int mid=(tL+tR)>>1,z=query(1,N,rt[i->l-1],rt[mid],t-i->val);
					if(z>=x) res=mid,tR=mid-1;
					else tL=mid+1;
				}
				auto j=split(res+1);
				double g=i->val;
				if(res!=i->l) x-=query(1,N,rt[i->l-1],rt[res-1],t-g);
				int Z=min((int)round((t-g)*R[res]),C[res])-x;
				auto sdt=st.begin();
				++sdt;
				st.erase(sdt,j);
				if(res>1) st.insert(Node(1,res-1,t));
				st.insert(Node(res,res,t-1.0*Z/R[res]));
				x=0;
				break;
			}
		}
#ifdef local
		printf("%lld\n",ans);
#endif
	}
	printf("%lld\n",ans);
	return 0;
}