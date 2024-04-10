// Problem: E. Little Pony and Lord Tirek
// Contest: Codeforces - Codeforces Round #259 (Div. 1)
// URL: https://codeforces.com/problemset/problem/453/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int s[100003],c[100003],r[100003],rk[100003],rt[100003];
double z[100003],lsh[100003],a[100003];
int sc[3000003],sr[3000003],ls[3000003],rs[3000003],cnt;
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
		++cnt,sc[cnt]=sc[x]+tc,sr[cnt]=sr[x]+tr;
		return cnt;
	}
	int mid=(nl+nr)>>1,y=++cnt;
	sc[y]=sc[x]+tc,sr[y]=sr[x]+tr;
	if(pos<=mid) rs[y]=rs[x],ls[y]=update(nl,mid,pos,ls[x],tc,tr);
	else ls[y]=ls[x],rs[y]=update(mid+1,nr,pos,rs[x],tc,tr);
	return y;
}
int query(int l,int r,int x,int y,double z)
{
	if(l==r) return min((int)round(z*(sr[y]-sr[x])),sc[y]-sc[x]);
	int mid=(l+r)>>1;
	if(lsh[mid]<=z) return sc[ls[y]]-sc[ls[x]]+query(mid+1,r,rs[x],rs[y],z);
	else return query(l,mid,ls[x],ls[y],z)+(int)round(z*(sr[rs[y]]-sr[rs[x]]));
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
set<pair<int,int>> tmp;
void assign(int l,int r,double t)
{
	auto itr=split(r+1),itl=split(l);
	int ans=0;
	auto ST=tmp.lower_bound(make_pair(l,0)),ED=ST;
	while(ED!=tmp.end()&&ED->first<=r) ans+=ED->second,++ED;
	tmp.erase(ST,ED);
	for(auto i=itl; i!=itr; ++i)
		ans+=query(1,N,rt[i->l-1],rt[i->r],t-i->val);
    st.erase(itl,itr),st.insert((Node){l,r,t});
    printf("%lld\n",ans);
}
signed main()
{
	st.insert(Node(-1000000,0,0)),st.insert(Node(n+1,1000000,0));
	for(int i=1; i<=n; ++i) 
	{
		s[i]=read(),c[i]=read(),r[i]=read();
		if(r[i]) st.insert(Node(i,i,-1.0*s[i]/r[i])),lsh[i]=z[i]=1.0*c[i]/r[i];
		else st.insert(Node(i,i,0)),tmp.insert(make_pair(i,s[i])),c[i]=r[i]=0;
	}
	sort(lsh+1,lsh+n+1),N=unique(lsh+1,lsh+n+1)-lsh-1;
	// for(int i=1; i<=N; ++i) printf("%.3lf\n",lsh[i]);
	for(int i=1; i<=n; ++i) rk[i]=lower_bound(lsh+1,lsh+N+1,z[i])-lsh;
	rt[0]=build(1,N);
	for(int i=1; i<=n; ++i) rt[i]=update(1,N,rk[i],rt[i-1],c[i],r[i]);
	for(int T=read(),t,l,r; T--;)
		t=read(),l=read(),r=read(),assign(l,r,t);
	return 0;
}