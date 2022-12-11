#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,m,x,num[2][2];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x&1)num[0][1]++;
		else num[0][0]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(x&1)num[1][1]++;
		else num[1][0]++;
	}
	printf("%d",min(num[0][1],num[1][0])+min(num[0][0],num[1][1]));
	return 0;
}