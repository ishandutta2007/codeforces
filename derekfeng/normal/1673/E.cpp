#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20);
int n,k,b[N+5];
int num[2][N+5];
int ans[N+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=0;i<2;i++){
		int t=k-2+i,T=t-1;
		num[i][0]=(t<=0);
		for(int j=1;j<=n;j++)
			if(T>=0)num[i][j]=((j-1)&T)==T;
	}
	for(int i=1;i<=n;i++){
		int x=b[i];
		for(int j=i;j<=n;j++){
			if(j>i){
				if(b[j]>=20)break;
				int t=(1<<b[j]);
				if((long long)x*t>=N)break;
				x*=t;
			}
			if(i==1&&j==n){
				if(k==0)ans[x]^=1;
				break;
			}
			int len=max(i-2,0)+max(n-j-1,0);
			int w=(i==1||j==n);
			if(num[w][len])ans[x]^=1; 
		}
	}
	int ok=0;
	for(int i=N-1;~i;i--){
		if(ans[i])ok=1;
		if(ok)putchar(ans[i]+'0');
	}
	if(!ok)puts("0");
}