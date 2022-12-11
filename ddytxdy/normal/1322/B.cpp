#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+50,M=4e7;
int n,a[N],ans,tmp[30];
struct node{int cnt[M];int *operator [](int x){return cnt+(1<<x)-1;}}cnt;
int calc(int x){
	int mx=(1<<x)-1,pp=1<<x-1,sum=0;LL ret=0;
	for(int i=pp+1;i<=mx;i++)sum+=cnt[x][i];
	for(int i=0;i<=mx;i++){
		sum+=cnt[x][(pp-i+mx+1)%(mx+1)];
		ret+=1ll*cnt[x][i]*sum;
		sum-=cnt[x][mx-i];
	}
	return ((ret-tmp[x-1])/2)&1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<=24;j++)tmp[j]+=((2*a[i])>>j&1);
		for(int j=0;j<=24;j++)
			cnt[j][a[i]&((1<<j)-1)]+=1;
	}
	for(int i=1;i<=24;i++){
		ans^=calc(i)*(1<<i-1);
	}
	int mx=1<<24;LL ret=0,sum=0;
	for(int i=0;i<mx;i++){
		sum+=cnt[24][mx-i];
		ret+=sum*cnt[24][i];
	}
	ans^=(((ret-tmp[24])/2)&1)*(1<<24);
	cout<<ans;
	return 0;
}