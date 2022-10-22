#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[1010],num[201000],res=1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&num[i]),cnt[num[i]%m]++;
	for(int i=0;i<m;i++)if(cnt[i]>1){puts("0");return 0;}
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)res=abs(num[i]-num[j])%m*res%m;
	printf("%d\n",res);
	return 0;
}