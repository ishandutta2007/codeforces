#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int num[10][1000005];//number of x in 1 ... j which g(x) = i;
int g[1000005];
int q,l,r,k;
int main(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++) num[j][i] = num[j][i-1];
		g[i] = i;
		num[i][i]++;
	}
	
	for(int i=10;i<=1000000;i++){
		for(int j=1;j<=9;j++) num[j][i] = num[j][i-1];
		int x = i, res = 1;
		while(x){
			int a = x % 10;
			x /= 10;
			if(a != 0) res *= a;
		}
		g[i] = g[res];
		num[g[res]][i]++;
	}
	
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",num[k][r] - num[k][l-1]);
	}
	return 0;
}