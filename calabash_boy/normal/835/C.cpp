#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int a[15][MAX][MAX];
int sum[15][MAX][MAX];
int n,q,c,x,y,s,x1,x2,y1,y2,t,MOD;
long long work(int t,int x1,int y1,int x2,int y2){
	long long ans = 0;
	for (int i = 0;i<=c;i++){
		int delta = (i+t)%MOD;
		if (delta==0){
			continue;
		}
		int num = sum[i][x2][y2]-sum[i][x2][y1-1]-sum[i][x1-1][y2]+sum[i][x1-1][y1-1];
		ans+=num*delta;
//		cout<<"ansDelta "<<i<<" "<<num<<" "<<delta<<endl;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&q,&c);
	MOD = c+1;
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&x,&y,&s);
		a[s][x][y]++;
	}
	for (int i = 0;i<=10;i++){
		for (int j = 1;j<=100;j++){
			for (int k = 1;k<=100;k++){
				sum[i][k][j]= sum[i][k][j-1];
				sum[i][k][j]+=a[i][k][j];
			}
		}
		for (int j = 1;j<=100;j++){
			for (int k = 1;k<=100;k++){
				sum[i][k][j]+=sum[i][k-1][j];
			}
		}
	}
	while (q--){
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		long long ans = work(t,x1,y1,x2,y2);
		printf("%d\n",ans);
	}
	return 0;
}