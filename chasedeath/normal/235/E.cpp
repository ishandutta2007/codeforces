#include<cstdio> 
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
int rd(){
	int s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2000+10,P=(1<<30);

int n,m,p;
int g[N][N],h[N][N];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
ll s1[N],s2[N];


int main(){
	n=rd(),m=rd(),p=rd();
	rep(i,1,N-1) rep(j,i,N-1) g[i][j]=gcd(i,j);
	rep(i,1,N-1) rep(j,1,i-1) g[i][j]=g[j][i];
	ui ans=0;
	rep(i,1,N-1) rep(j,1,N-1) if(g[i][j]==1) h[i][++h[i][0]]=j;
	if(n>m) swap(n,m);
	rep(a,1,p) {
		memset(s1,0,sizeof s1),memset(s2,0,sizeof s2);
		rep(i,1,n) if(g[a][i]==1) s1[i]=n/i;
		rep(i,1,m) if(g[a][i]==1) s2[i]=m/i;
		rep(i,1,m) for(int j=i+i;j<=m;j+=i) {
			s1[i]+=s1[j];
			s2[i]+=s2[j];
		}
		rep(i,1,m) s1[i]=s1[i]*s2[i];
		drep(i,m,1) for(int j=i+i;j<=m;j+=i) s1[i]-=s1[j];
		ans+=(p/a)*s1[1];
	}
	printf("%u\n",ans%P);
}