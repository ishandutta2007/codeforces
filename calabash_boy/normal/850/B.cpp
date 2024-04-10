#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+100;
const int MAXX = 2e6+100;
int prime[MAXX];
int a[MAX];
int sum1[MAXX];
long long sum2[MAXX];
bool vis[MAXX];
int tot;
int n,x,y;
long long ans = 0x3f3f3f3f3f3f3f3fLL;
void input(){
	scanf("%d%d%d",&n,&x,&y);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		sum1[a[i]]++;
		sum2[a[i]]+=a[i];
	}
}
void init(){
	for (int i=1;i<=2e6;i++){
		sum1[i]+=sum1[i-1];
		sum2[i]+=sum2[i-1];
	}
	for (int i=2;i<=1e6;i++){
		if (!vis[i]){
			prime[tot++] = i;
			vis[i] = true;
		}
		for (int j=0;j<tot;j++){
			int temp = i*prime[j];
			if (temp>1e6){
				break;
			}
			vis[temp] = true;
		}
	}
}
void solve(){
	for (int i=0;i<tot;i++){
		long long res =0;
		int P = prime[i];
		int k = min(x/y,P-1);
		for (int j=0;j<=1e6;j+=P){
			res+=1LL*(sum1[j+P-k-1]-sum1[j])*x;
			res+=(1LL*(sum1[j+P-1]-sum1[j+P-k-1])*(j+P)-sum2[j+P-1]+sum2[j+P-k-1])*y;
		}
//		cout<<P<<" "<<res<<endl;
		ans = min(ans,res);
	}
	printf("%I64d\n",ans);
}
int main(){
	input();
	init();
	solve();
	return 0;
}