#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e2+10;
int n;
LL a[maxn];
int cnt2[maxn],cnt3[maxn];
int rk[maxn];
void work(int ii){
	LL x = a[ii];
	while (x%2==0){
		x/=2;
		cnt2[ii]++;
	}
	while (x%3==0){
		x/=3;
		cnt3[ii]++;
	}
}
bool cmp(int x,int y){
	return cnt3[x]>cnt3[y]||cnt3[x]==cnt3[y]&&cnt2[x]<cnt2[y];
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%I64d",a+i);
		rk[i] =i;
		work(i);
	}
	sort(rk,rk+n,cmp);
	for (int i=0;i<n;i++){
		printf("%I64d ",a[rk[i]]);
	}
	puts("");
	return 0;
}