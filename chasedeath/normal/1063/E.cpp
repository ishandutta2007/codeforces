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

const int N=1010,INF=1e9+10;

int n;
int A[N],vis[N];
char s[N][N];

int main(){
	n=rd();
	rep(i,1,n) A[i]=rd();
	int ans=0;
	int p=1;
	rep(i,1,n) rep(j,1,n) s[i][j]='.';
	int f=1;
	rep(i,1,n) if(A[i]!=i) f=0;
	if(f) {
		printf("%d\n",n);
		rep(i,1,n) puts(s[i]+1);
		return 0;
	}
	rep(i,1,n-1) if(A[i]!=i && !vis[i]) {
		int j=i,c1=1,c2=0;
		while(A[j]!=i) j=A[j],c1++;
		j=i;
		while(j!=n && A[j]!=i) j=A[j],c2++;
		//cout<<"$"<<i<<' '<<c1<<' '<<c2<<' '<<j<<endl;
		if(c2==c1-1 && j==n) {
			j=i;
			while(j!=n && A[j]!=i) {
				//cout<<"Go "<<j<<' '<<A[j]<<endl;
				vis[A[j]]=1;
				if(A[j]>j) s[p][j]=s[p][A[j]]='/';
				else s[p][j]=s[p][A[j]]='\\';
				p++,j=A[j];
				ans++;
			}
			vis[i]=1;
		}
	}
	rep(i,1,n-1) if(A[i]!=i && !vis[i]) {
		int j=i,c1=1,c2=0,lst=0;
		while(A[j]!=i) j=A[j],c1++;
		j=i;
		while(j!=n && A[j]!=i) lst=A[j]>j,j=A[j],c2++;
		if(c2==c1-1 && (j==n || lst)) {
			int t=p++;
			j=i;
			while(j!=n && A[j]!=i) {
				//cout<<"Go "<<j<<' '<<A[j]<<endl;
				vis[A[j]]=1;
				if(A[j]>j) s[p][j]=s[p][A[j]]='/';
				else s[p][j]=s[p][A[j]]='\\';
				p++,j=A[j];
				ans++;
			}
			vis[i]=1;
			if(j!=n) {
				s[p-1][n]='/',s[t][n]='\\',s[t][A[j]]='\\';
				ans++;
			}
		}
	}
	rep(i,1,n-1) if(A[i]==i) ans++;
	printf("%d\n",ans);
	rep(i,1,n) puts(s[i]+1);
}