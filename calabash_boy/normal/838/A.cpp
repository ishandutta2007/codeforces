#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 2550;
bool mp[MAX][MAX];
int sum[MAX][MAX];
char ta[MAX];
int m,n;
void input(){
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",ta+1);
		for (int j=1;j<=m;j++){
			sum[i][j] = sum[i][j-1];
			char tt = ta[j];
			if (tt=='1'){
				mp[i][j] = true;
				sum[i][j]++;
			}else{
				mp[i][j] = false;
			}
		}
		for (int j=1;j<=m;j++){
			sum[i][j] +=sum[i-1][j];
		}
	}
//	printf("end\n");
}
int calc(int k){
	int size = k*k;
	int tot=0;
	for (int i=1;i<=n;i+=k){
		for (int j=1;j<=m;j+=k){
			int ii = min(n,i+k-1);
			int jj = min(m,j+k-1);
			int temp = sum[ii][jj]-sum[ii][j-1]-sum[i-1][jj]+sum[i-1][j-1];
			tot+=min(temp,size-temp);
//			printf("%d %d %d\n",i,j,tot);
		}
	}
//	printf("%d %d\n",k,tot);
	return tot;
}
int ans = INF;
void work(){
	for (int k =2;k<=max(m,n);k++){
		ans = min(calc(k),ans);
	}
	printf("%d\n",ans);
}
void print(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%d ",sum[i][j]);
		}
		printf("\n");
	}
}
int main(){
	input();
//	print();
	work();
	return 0;
}