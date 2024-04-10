#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
const int MOD = 1e9+7;
int mu[MAX];
bool vis[MAX];
int nums[MAX];
int a[MAX];
long long bas[MAX];
int prime[MAX];
int  n;
int tot =0;
int top=-1;
void input(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		top = max(top,a[i]);
		for (int j=1;j*j<=a[i];j++){
			if (a[i]%j==0){
				int temp = a[i]/j;
				if (temp==j){
					nums[temp]++;
				}else{
					nums[temp]++;
					nums[j]++;
				}
			}
		}
	}
}
void init(){
	mu[1]=1;
	for (int i=2;i<=top;i++){
		if (!vis[i]){
			mu[i] =-1;
			prime[tot++] = i;
		}
		for (int j=0;j<tot;j++){
			int temp = i*prime[j];
			if (temp>top){
				break;
			}
			vis[temp] = true;
			if (i%prime[j]){
				mu[temp] = -mu[i];
			}else{
				mu[temp] = 0;
				break;
			}
		}
	}
	bas[0] =1;
	for (int i=1;i<=1000000;i++){
		bas[i] = bas[i-1]*2%MOD;
	}
}
void solve(){
	long long ans = 0;
	for (int i=2;i<=top;i++){
		long long tempans=0;
		int ii = i;
		int x=1;
		while (ii<=top){
			if (nums[ii]>0)
			tempans+=1LL*mu[x]*nums[ii]*bas[nums[ii]-1]%MOD;
			tempans%=MOD;
			x++;
			ii+=i;
		}
		ans+=tempans*i%MOD;
		ans%=MOD;
	}
	printf("%I64d\n",ans);
}
int main(){
	input();
	init();
	solve();
	return 0;
}