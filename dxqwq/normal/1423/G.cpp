// Problem: G. Growing flowers
// Contest: Codeforces - Bubble Cup 13 - Finals [Online Mirror, unrated, Div. 1]
// URL: https://codeforces.com/problemset/problem/1423/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct Node{
    int l,r,v;
    Node(int a=-1,int b=-1,int c=0){l=a,r=b,v=c;}
    bool operator<(const Node&a)const{return l<a.l;}
};
set<Node> st,s[200003];
set<Node>::iterator split(int pos)
{
    auto it=st.lower_bound(Node(pos));
    if (it!=st.end()&&it->l==pos) return it;
    --it;Node tmp=*it;st.erase(it),
    s[tmp.v].erase(tmp),s[tmp.v].insert(Node(tmp.l,pos-1,tmp.v)),
    s[tmp.v].insert(Node(pos,tmp.r,tmp.v)),
    st.insert(Node(tmp.l,pos-1,tmp.v));
    return st.insert(Node(pos,tmp.r,tmp.v)).first; 
}
ll t1[100003];
int t0[100003];
int n=read(),m=read();
void a0(int x,int k)
{
	while(x<=n) t0[x]+=k,x+=x&(-x);
	return ;
}
void a1(int x,ll k)
{
	while(x<=n) t1[x]+=k,x+=x&(-x);
	return ;
}
int q0(int x)
{
	int r=0;
	while(x) r+=t0[x],x-=x&(-x);
	return r;
}
ll q1(int x)
{
	ll r=0;
	while(x) r+=t1[x],x-=x&(-x);
	return r;
}
void ins(Node t)
{
	int nxt=s[t.v].upper_bound(t)->l,pre=(--s[t.v].lower_bound(t))->r;
	a0(nxt-pre-1,-1),a1(nxt-pre-1,-nxt+pre+1),
	(pre+1!=t.l)&&(a0(t.l-pre-1,1),a1(t.l-pre-1,t.l-pre-1),0),
	(nxt-1!=t.r)&&(a0(nxt-t.r-1,1),a1(nxt-t.r-1,nxt-t.r-1),0),
	s[t.v].insert(t);
}
void del(Node t)
{
	int nxt=s[t.v].upper_bound(t)->l,pre=(--s[t.v].lower_bound(t))->r;
	a0(nxt-pre-1,1),a1(nxt-pre-1,nxt-pre-1),
	(pre+1!=t.l)&&(a0(t.l-pre-1,-1),a1(t.l-pre-1,-t.l+pre+1),0),
	(nxt-1!=t.r)&&(a0(nxt-t.r-1,-1),a1(nxt-t.r-1,-nxt+t.r+1),0),
	s[t.v].erase(t);
}
void assign(int l,int r,int v)
{
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl; i!=itr; ++i) del(*i);
    st.erase(itl,itr),st.insert(Node(l,r,v)),ins(Node(l,r,v));
}
map<int,int> mp;
int cnt=0;
int rcol()
{
	int res=read();
	if(!mp[res]) mp[res]=++cnt;
	return mp[res];
}
signed main()
{
	for(int i=1; i<=n; ++i) s[i].insert(Node(-1,0)),s[i].insert(Node(n+1,n+2));
	st.insert(Node(-1,0,0)),st.insert(Node(n+1,n+2,0)),
	a0(n,n),a1(n,1ll*n*n);
	for(int i=1,x; i<=n; ++i) x=rcol(),ins(Node(i,i,x)),st.insert(Node(i,i,x));
	for(int op,l,r,x; m--;)
	{
		op=read();
		if(op==1) l=read(),r=read(),x=rcol(),assign(l,r,x);
		else x=read(),printf("%lld\n",1ll*n*(n+1-x)-q1(n)+q1(x-1)+1ll*(q0(n)-q0(x-1))*(x-1));
	}
	return 0;
}