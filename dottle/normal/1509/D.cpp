#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

inline void MAX(int &a,const int &b) {if(b>a) a=b;}
inline void MIN(int &a,const int &b) {if(b<a) a=b;}
inline int max(const int &a,const int &b) {return a>b?a:b;}
inline int min(const int &a,const int &b) {return a<b?a:b;}

const int N=3e5+5;

int T,n;
int a[3][N];
int c[3][2];
int w1[N],w2[N],w[N];
int ans[N];

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=0 ; i<3 ; ++i)
			for(int j=0 ; j<2 ; ++j)
				c[i][j]=0;
		for(int l=0 ; l<3 ; ++l)
			for(int i=1 ; i<=2*n ; ++i)
				scanf("%1d",&a[l][i]),++c[l][a[l][i]];
		bool flag=0;
		for(int x=0 ; x<3&&!flag ; ++x)
			for(int y=x+1 ; y<3&&!flag ; ++y) {
				if((c[x][1]>=n&&c[y][1]>=n)) {
					flag=1;
					int tot1=max(c[x][1],c[y][1]),n1=0,n2=0,c=0,r1,r2;
					for(int i=1 ; i<=2*n ; ++i) {
						if(a[x][i]==0) ++c;
						else w1[++n1]=c,c=0;
					}
					w1[++n1]=c,c=0;
					for(int i=1 ; i<=2*n ; ++i) {
						if(a[y][i]==0) ++c;
						else w2[++n2]=c,c=0;
					}
					w2[++n2]=c,c=0;
					if(n1>n2) {
						for(int i=1 ; i<=n1 ; ++i) swap(w1[i],w2[i]);
						swap(n1,n2);
					}
					for(int i=1 ; i<=n2 ; ++i) w[i]=max(w1[i],w2[i]);
					for(int i=1 ; i<=tot1 ; ++i) {
						for(int j=1 ; j<=w[i] ; ++j) printf("0");
						printf("1");
					}
					if(w[tot1+1]) for(int i=1 ; i<=w[tot1+1] ; ++i) printf("0");
					for(int i=1 ; i<=max(n1,n2) ; ++i) w[i]=w1[i]=w2[i]=0;
				}
				else if(c[x][0]>=n&&c[y][0]>=n) {
					flag=1;
					int tot1=max(c[x][0],c[y][0]),n1=0,n2=0,c=0,r1,r2;
					for(int i=1 ; i<=2*n ; ++i) {
						if(a[x][i]==1) ++c;
						else w1[++n1]=c,c=0;
					}
					w1[++n1]=c,c=0;
					for(int i=1 ; i<=2*n ; ++i) {
						if(a[y][i]==1) ++c;
						else w2[++n2]=c,c=0;
					}
					w2[++n2]=c,c=0;
					if(n1>n2) {
						for(int i=1 ; i<=n1 ; ++i) swap(w1[i],w2[i]);
						swap(n1,n2);
					}
					for(int i=1 ; i<=n2 ; ++i) w[i]=max(w1[i],w2[i]);
					for(int i=1 ; i<=tot1 ; ++i) {
						for(int j=1 ; j<=w[i] ; ++j) printf("1");
						printf("0");
					}
					if(w[tot1+1]) for(int i=1 ; i<=w[tot1+1] ; ++i) printf("1");
					for(int i=1 ; i<=max(n1,n2) ; ++i) w[i]=w1[i]=w2[i]=0;
				}
			}
		puts("");
	}
	return 0;
}