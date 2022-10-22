#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <string>
#include <map>
#include <set>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
#define Fq(i,x) for(int i=I[x];i;i=Q[i].nx)
using namespace std;
typedef long long ll;
const int MX=1e5+100;
struct Star{int y,nx;}E[MX];
int H[MX],ec;
void add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

map<string,int> mp;
int namecnt;

int N,M;
int F[MX];
int D[MX];
int X[MX];

void dfs1(int x,int d)
{
	D[x]=d;
	Fe(i,x)dfs1(E[i].y,d+1);
}

struct Query{int k,id,nx;}Q[MX];
int I[MX],qc;
void addq(int x,int k,int id)
{
	Q[++qc].k=k,Q[qc].id=id,Q[qc].nx=I[x],I[x]=qc;
}

int Ans[MX];
typedef set<int>::iterator It;

struct Seg
{
	set<int> v;
	int L,R;
	void ins(int i,int x,int l=1,int r=N);
	int ask(int i,int l=1,int r=N);
}T[MX<<5]; int tc;
void Open(int& x){if(!x)x=++tc;}
void Seg::ins(int i,int x,int l,int r)
{
	if(l==r){v.insert(x);return;}
	int m=(l+r)>>1;
	if(i<=m)Open(L),T[L].ins(i,x,l,m);
	else Open(R),T[R].ins(i,x,m+1,r);
}
int Seg::ask(int i,int l,int r)
{
//	printf("ask %d [%d,%d]\n",i,l,r);
	if(l==r)
	{
		if(i!=l)return 0;
//		for(It it=v.begin();it!=v.end();++it)printf("%d ",*it);
//		printf("\n");
		return v.size();
	}
	int m=(l+r)>>1;
	if(i<=m)return T[L].ask(i,l,m);
	else return T[R].ask(i,m+1,r);
}
void MergeSet(set<int>& a,set<int>& b)
{
	for(It it=b.begin();it!=b.end();++it)a.insert(*it);
	b.clear();
//	printf("MergeSet!!!\n");
}
int Merge(int a,int b,int l=1,int r=N)
{
//	printf("Merge :%d %d [%d,%d]\n",a,b,l,r);
	if(!a||!b)return a+b;
	if(l==r)
	{
		int sa=T[a].v.size(),sb=T[b].v.size();
		if(sa>sb){MergeSet(T[a].v,T[b].v);return a;}
		else {MergeSet(T[b].v,T[a].v);return b;}
	}
	int m=(l+r)>>1;
	T[a].L=Merge(T[a].L,T[b].L,l,m);
	T[a].R=Merge(T[a].R,T[b].R,m+1,r);
	return a;
}

#define y E[i].y
int t[MX];
void dfs2(int x)
{
//	printf("%d\n",x);
	Fe(i,x)dfs2(y);
	Fe(i,x)t[x]=Merge(t[x],t[y]);
	Fq(i,x)Ans[Q[i].id]=T[t[x]].ask(Q[i].k);
//	Fq(i,x)printf("queryid=%d\n",Q[i].id),Ans[Q[i].id]=T[t[x]].ask(Q[i].k),printf("\n");
}
#undef y

int main()
{
	scanf("%d",&N);
	char s[30];
	Fr(i,1,N)
	{
		scanf("%s%d",s,F+i);
		if(F[i])add(F[i],i);
		int& name=mp[s];
		if(!name)name=++namecnt;
		X[i]=name;
	}
	Fr(i,1,N)if(!F[i])dfs1(i,1);
//	Fr(i,1,N)printf("%d\n",D[i]);
	Fr(i,1,N)Open(t[i]),T[t[i]].ins(D[i],X[i]);
	
	scanf("%d",&M);
	int x,k;
	Fr(i,1,M)
	{
		scanf("%d%d",&x,&k);
		addq(x,k+D[x],i);
	}
	
	Fr(i,1,N)if(!F[i])dfs2(i);
	Fr(i,1,M)printf("%d\n",Ans[i]);
	
	return 0;
}