#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=1e5+100;
char C[MX];
int S[MX];

struct Data{int cnt[26];};
Data operator+(Data a,Data b)
{
	Data c;
	Fill(c.cnt,0);
	Fo(k,0,26)c.cnt[k]=a.cnt[k]+b.cnt[k];
	return c;
}
struct Seg
{
	Data v;
	int z,l,r;
	Seg *L,*R;
	void update(int x){Fill(v.cnt,0),v.cnt[x]=r-l+1,z=x;}
	void pushup(){v=L->v+R->v;}
	void pushdown(){if(z!=-1)L->update(z),R->update(z),z=-1;}
	void init(int a,int b);
	void set(int a,int b,int ch);
	Data ask(int a,int b);
	void dfs();
}T[MX<<1],*tcnt=T;
Seg* New(){return ++tcnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,z=-1;
	if(l==r){v.cnt[S[l]]=1;return;}
	int m=(l+r)>>1;
	L=New(),L->init(l,m);
	R=New(),R->init(m+1,r);
	pushup();
}
void Seg::set(int a,int b,int ch)
{
	if(a<=l&&r<=b){update(ch);return;}
	pushdown();
	if(a<=L->r)L->set(a,b,ch);
	if(b>=R->l)R->set(a,b,ch);
	pushup();
}
Data Seg::ask(int a,int b)
{
	if(a<=l&&r<=b)return v;
	pushdown();
	if(b<=L->r)return L->ask(a,b);
	if(a>=R->l)return R->ask(a,b);
	return L->ask(a,b)+R->ask(a,b);
}
void Seg::dfs()
{
	if(l==r)
	{
		Fo(k,0,26)if(v.cnt[k]){putchar(k+'a');break;}
		return;
	}
	pushdown();
	L->dfs();
	R->dfs();
}


int N,M;


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%s",&N,&M,C+1);
	Fr(i,1,N)S[i]=C[i]-'a';
	T->init(1,N);
	int a,b;
	Fr(i,1,M)
	{
		scanf("%d%d",&a,&b);
		Data v=T->ask(a,b);
//		Fo(i,0,26)if(v.cnt[i])printf("%c %d\n",i+'a',v.cnt[i]);
		int x=0;
		Fo(k,0,26)x+=v.cnt[k]&1;
		if(x>1)continue;
		int l=a,r=b;
		Fo(k,0,26)
		{
			int n=v.cnt[k];
			if(n&1)T->set((a+b)>>1,(a+b)>>1,k),--n;
			if(!n)continue;
			T->set(l,l+n/2-1,k),l+=n/2;
			T->set(r-n/2+1,r,k),r-=n/2;
		}
	}
	T->dfs();
	putchar('\n');
	return 0;
}