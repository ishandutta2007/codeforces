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

const int N=1e5+10,P=998244353;

int n;
char s[N];
int a[N];
int fx[N],fy[N];

int A[N],C;

int Go(int x){
	rep(i,1,n) a[i]=-1;
	C=0,a[n]=x;
	rep(i,1,n) if(~fx[i]) a[i]=fx[i]*a[n]+fy[i];
	drep(i,n-1,1) if(~a[i+1] && a[i+1]<=i) a[i]=a[i+1];
	//rep(i,1,n) cout<<a[i]<<' ';
	//puts("");
	rep(i,1,n) if(a[i]==-1) {
		if(s[i]=='_') {
			if(i>a[i-1]+1 && a[i+1]==-1) a[i]=i;
			else a[i]=a[i-1];
		} else a[i]=a[i-1];
	}
	//rep(i,1,n) cout<<a[i]<<' ';
	//puts("");
	int f=1;
	rep(i,1,n) if(a[i]!=a[i-1]) A[++C]=a[i]-a[i-1]-1,f&=A[C]>0;
	rep(i,1,n) {
		if(s[i]=='_') f&=a[n]-a[i]<=n-i;
		else f&=a[n]-a[i]>n-i;
		//cout<<"$"<<i<<' '<<f<<endl;
	}
	if(!f) return 0;
	printf("%d\n",C);
	rep(i,1,C) printf("%d ",A[i]);
	return 1;
}

int main(){
	scanf("%s",s+1),n=strlen(s+1),s[++n]='_';
	rep(i,1,n) fx[i]=-1;
	fx[1]=0;
	int l=0,r=n-(s[1]=='_'),lst=0;
	if(s[1]=='#') cmax(l,n);
	rep(i,2,n-1) {
		if(s[i]=='_' && s[i-1]=='#') {
			fy[i]=i,fx[i]=0; 
			if(i<n) fy[i+1]=i,fx[i+1]=0;
			cmax(l,i),lst=i;
		}
		if(s[i]=='#' && s[i-1]=='_') {
			fx[i]=1,fy[i]=-n+i-1,cmax(l,lst-fy[i]);
			if(~fx[i-1]) {
				if(fx[i-1]==fx[i]) {
					if(fy[i]!=fy[i-1]) return puts("-1"),0;
				} else {
					int t=fy[i-1]-fy[i];
					cmax(l,t),cmin(r,t);
				}
			} else fx[i-1]=fx[i],fy[i-1]=fy[i];
		}
	}
	if(l>r) return puts("-1"),0;
	//cout<<"$"<<l<<' '<<r<<endl;
	rep(i,l,r) if(Go(i)) return 0;
	puts("-1");
}