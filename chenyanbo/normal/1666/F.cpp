#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)
#define N 5010
#define MO 998244353
int d,r,m,T,A[N][N],f[N][N],n,e[N],s[N],op[N];

int main(){
	
	scanf("%d",&T);
	/*
	for(int i=0;i<=5000;++i){
		int o;
		A[i][o=0] = 1;
		for(int j=i;j;--j){
			++o;
			A[i][o]=(ll)A[i][o-1]*j%MO;
		}
	}
	*/
	A[0][0]=1;
	for(int i=0;i<=5000;++i){
		A[i][0] = 1;
		for(int j=1;j<=i;++j){
			A[i][j]=(A[i-1][j-1]+A[i-1][j])%MO;
		}
	}
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)op[i]=0; m=0;
		for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)f[i][j]=0;
		for(int i=1;i<=n;++i)scanf("%d",&r),++op[r];
		for(int i=n;i;--i)if(op[i])e[++m]=op[i];
		for(int i=1;i<=m;++i)s[i] = s[i-1] + e[i];
		f[0][0] = 1;
		for(int i=0;i<m;++i){
			for(int j=0;j<=i;++j)if(f[i][j]){
				d = j-(s[i]-j);
				if(j!=n/2)--d;
				if(d>=0) f[i+1][j]=((ll)f[i+1][j]+(ll)f[i][j]*A[d][e[i+1]])%MO;
				if(i){
					d=j-1-(s[i]-j); //*e[i+1]
					if(d>=0) f[i+1][j+1]=((ll)f[i+1][j+1]+(ll)f[i][j]%MO*A[d][e[i+1]-1])%MO;
				}else {
					if(e[i+1]==1){
						f[i+1][j+1]=((ll)f[i+1][j+1]+(ll)f[i][j])%MO;
					}
				}
			}
		}
		
//		for(int i=0;i<=6;++i)
//		{
//			for(int j=0;j<=6;++j)printf("%d ",f[i][j]);
//			puts("");
//	}
		
		printf("%d\n",f[m][n/2]);
	}
	
}
/*
1
8
1 1 2 3 4 4 6 7


1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 2 0 0
0 0 0 2 4 0
0 0 0 0 14 18

*/