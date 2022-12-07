#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}
#define N 1234
#define fir first
#define sec second
int n,ln,rn,r[N],a[N][N],b[N][N];
pair<int,int>l[N];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n-3;i++)
		scanf("%d%d",&j,&k),a[j][k]=a[k][j]=1;
	for(i=1;i<=n-3;i++)	
		scanf("%d%d",&j,&k),b[j][k]=b[k][j]=1;
	for(i=2;i<=n;i++)
		for(j=n;j>i+1;j--){
			if(a[i][j]){
				l[++ln]=make_pair(i,j);
				a[i][j]=a[j][i]=0;
			}
		}	
	for(i=2;i<=n;i++)
		for(j=n;j>i+1;j--)if(b[i][j]){
			for(k=j-1;k>i;k--)if(b[i][k]||k==i+1)break;
			r[++rn]=k;
			b[i][j]=b[j][i]=0;
			b[1][k]=b[k][1]=1;
		}
	printf("%d\n",ln+rn);
	for(i=1;i<=ln;i++)printf("%d %d\n",l[i].fir,l[i].sec);
	for(i=rn;i;i--)printf("1 %d\n",r[i]);
	return 0;
}