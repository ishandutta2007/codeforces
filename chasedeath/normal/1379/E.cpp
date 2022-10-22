#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;

#define NO puts("NO"),exit(0)

int n,m;
int fa[N];

int chk(int a,int b) {
	if(a>b) swap(a,b);
	return a*2<=b;
}

void Out(){
	puts("YES");
	rep(i,1,n) printf("%d ",fa[i]);
	exit(0);
}

int Get(int l,int r) {
	rep(i,l+1,r) fa[i]=l-1+(i-l+1)/2;
	return l;
}

int Mincost(int x){
	if(~x&1) return 1e9;
	rep(i,0,17) if(x+1==(1<<i)) return 0;
	return 1;
}


int main(){
	n=rd(),m=rd();
	if(Mincost(n)==m) Get(1,n),Out();
	if(m==0) NO;
	if(~n&1) NO;
	if((m+1)*2>=n) NO;
	int r=(m+1)*2+1;
	
	if(r==n) {
		rep(i,1,m+1) fa[i*2]=i*2-1,fa[i*2+1]=i*2-1;
		Out();
	}

	r-=2;
	int c=n-r+2;
	if(m>1) rep(x,1,c-1) if(Mincost(x)+Mincost(c-x)-!chk(c-x,n-1-(c-x))+(x>=3)==1) {
		//puts("!!");
		//cout<<x<<' '<<c-x<<endl;
		rep(i,1,m) fa[i*2]=i*2-1,fa[i*2+1]=i*2-1;
		int t=max(0,r-2);
		fa[Get(r-1,r+x-2)]=t;
		fa[2]=t;
		fa[Get(r+x-1,n)]=1;
		//cout<<"$"<<r-1<<' '<<fa[r-1]<<endl;
		Out();
	}
	NO;
}