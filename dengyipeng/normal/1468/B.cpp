#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define file
using namespace std;

int a[200001];
double sum[200001];
int n,Q,i,j,k,l,ans,s,S,K;
double Find;
int Find2;

struct P{
	int x;
	double y;
};
vector<P> d[800001];
double xl(P a,P b) {return (b.y-a.y)/(b.x-a.x);}

struct Set{
	int x,y,s;
} ss;
struct Heap{
	int x,y;
	double t;
	int tt;
} ss2;

bool operator < (Set a,Set b) {return a.s>b.s || a.s==b.s && a.x<b.x  || a.s==b.s && a.x==b.x && a.y<b.y;}
set<Set> st;
set<Set> :: iterator si;
bool operator < (Heap a,Heap b) {return !(a.t<b.t);}
priority_queue<Heap> hp;

void Add(vector<P> &a,P b)
{
	int i,j,k,l,t=a.size();
	while (t>1 && xl(a[t-2],a[t-1])>=xl(a[t-1],b)) --t,a.pop_back();
	a.push_back(b);
}
void mt(int t,int l,int r)
{
	int mid=(l+r)/2;
	int i;
	fo(i,l,r) Add(d[t],P{i,sum[i]});
	if (l==r) return;
	
	mt(t*2,l,mid);mt(t*2+1,mid+1,r);
}
void addp(P a,int x)
{
	double s=xl(P{x,sum[x]},a);
	if (s<=Find) Find=s,Find2=a.x;
}
void find2(vector<P> &a,int x)
{
	int i,j,k,t=a.size(),L,R,Mid;
	double s1,s2;
	
	addp(a[0],x);
	L=0,R=t-2;
	while (L<R)
	{
		Mid=(L+R)/2;
		s1=xl(P{x,sum[x]},a[Mid]);
		s2=xl(P{x,sum[x]},a[Mid+1]);
		if (s1-s2>=0) L=Mid+1;
		else R=Mid;
	}
	if (L) addp(a[L-1],x);
	addp(a[L],x);
	if (L+1<=t-1) addp(a[L+1],x);
}
void find(int t,int l,int r,int x,int y)
{
	int mid=(l+r)/2;
	if (x<=l && r<=y) {find2(d[t],x-1);return;}
	if (x<=mid) find(t*2,l,mid,x,y);
	if (mid<y) find(t*2+1,mid+1,r,x,y);
}

void add(int x,int y)
{
	int i,j,k,l;
	double T;
	st.insert(Set{x,y,y-x});
	if (x<y)
	{
		Find=2147483647;
		find(1,1,n,x,y-1);
		hp.push(Heap{x,y,Find,Find2});
	}
}
void del(int x,int y,Heap s)
{
	int i,j,k,l;
	st.erase(Set{x,y,y-x});
	add(x,s.tt),add(s.tt+1,y);
}

int main()
{
//	freopen("b.in","r",stdin);
//	#ifdef file
//	freopen("b.out","w",stdout);
//	#endif
	
	scanf("%d%d",&n,&Q);
	fo(i,1,n) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	mt(1,1,n);
	
	add(1,n);
	for (;Q;--Q)
	{
		scanf("%d",&K);ans=0;
		
		while (!hp.empty())
		{
			ss2=hp.top();
			if (ss2.t<=K) hp.pop(),del(ss2.x,ss2.y,ss2);
			else break;
		}
		
		si=st.begin();
		ss=*si;
		ans=ss.s;
		printf("%d ",ans);
	}
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}