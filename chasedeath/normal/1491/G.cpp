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

const int N=2e5+10,INF=1e9+10;

int n;
int a[N],vis[N],sz[N];
Pii b[N];
int c;

int X[N],Y[N],C,col[N];
void Swap(int x,int y){
	X[++C]=x,Y[C]=y;
	swap(a[x],a[y]),col[a[x]]^=1,col[a[y]]^=1;
}
void Solve(int i){ 
	while(!col[a[i]]) i=a[i];
	//cout<<"Stop "<<i<<endl;
	while(!col[a[a[i]]]) Swap(i,a[i]);
	i=a[i];
	while(i!=a[i]) Swap(i,a[i]);
}

int main(){
	n=rd();
	rep(i,1,n) a[i]=rd();
	rep(i,1,n) if(!vis[i]) {
		for(int j=i;!vis[j];j=a[j]) vis[j]=1,sz[i]++;
		if(sz[i]>1) b[++c]=mp(sz[i],i);
	}
	if(~c&1) {
		for(int i=1;i<=c;i+=2) {
			Swap(b[i].second,b[i+1].second);
			Solve(b[i].second);
		}
	} else if(c>1) {
		for(int i=1;i<=c-3;i+=2) {
			Swap(b[i].second,b[i+1].second);
			Solve(b[i].second);
		}
		Swap(b[c-2].second,b[c-1].second);
		Swap(b[c-1].second,b[c].second);
		Solve(b[c].second);
	} else if(c==1) {
		int i=b[1].second,t=a[i];
		if(b[1].first<n) {
			rep(j,1,n) if(a[j]==j) {
				 Swap(j,i);
				 Solve(i);
				 break;
			}
		} else {
			Swap(i,a[i]),Swap(t,a[i]);
			Solve(i);
		}
	}
	printf("%d\n",C);
	rep(i,1,C) printf("%d %d\n",X[i],Y[i]);
}