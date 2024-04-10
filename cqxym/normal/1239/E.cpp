#include<stdio.h>
#include<algorithm>
#define R register int
int a[60];
bool vis[58];
unsigned long long f[50][25][45314];
inline void Solve(){
	int n,ans=-1,sum=0,m;
	scanf("%d",&n);
	m=n-1<<1;
	for(R i=0;i!=n<<1;i++){
		scanf("%d",a+i);
	}
	std::sort(a,a+(n<<1));
	std::reverse(a,a+(n<<1));
	for(R i=0;i!=m;i++){
		sum+=a[i];
		const int Al=a[i]>>6,Ap=a[i]&63;
		for(R j=n-1;j!=-1;j--){
			const int maxA=j*3125+1>>1;
			for(R k=0;k<=maxA;k++){
				f[i+1][j][k]=f[i][j][k];
			}
			if(j!=0){
				for(R k=0;k<=maxA;k++){
					f[i+1][j][k+Al]|=f[i][j-1][k]<<Ap;
					if(Ap!=0){
						f[i+1][j][k+1+Al]|=f[i][j-1][k]>>64-Ap;
					}
				}
			}
		}
	}
	n--;
	for(R i=sum>>1;ans==-1;i--){
		if((f[m][n][i>>6]>>(i&63)&1)==1){
			ans=i;
		}
	}
	for(R i=0;i!=n<<1;i++){
		vis[i]=false;
	}
	printf("%d",a[n<<1]);
	int c=n,x;
	for(R i=m;i!=0&&c!=0;i--){
		x=ans-a[i-1];
		if(x>-1&&(f[i-1][c-1][x>>6]>>(x&63)&1)==1){
			ans=x;
			printf(" %d",a[i-1]);
			vis[i-1]=true;
			c--;
		}
	}
	puts("");
	for(R i=0;i!=n<<1;i++){
		if(vis[i]==false){
			printf("%d ",a[i]);
		}
	}
	printf("%d\n",a[n<<1|1]);
}
int main(){
	f[0][0][0]=1;
	Solve();
	return 0;
}