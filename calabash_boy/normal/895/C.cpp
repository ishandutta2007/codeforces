#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const int ZSC = 1e9+7;
const int N = 75;
int cnt[N];
int status[N];
long long dp[2][1024*1024];
int n;
int prime[N],tot;
int bas[maxn];
bool pri(int x){
	for (int i=2;i<x;i++){
		if (x%i==0)return false;
	}
	return true;
}
void init(){
	bas[0] =1;
	for (int i=1;i<=100000;i++)bas[i] = 2*bas[i-1]%ZSC;
	for (int i=2;i<=70;i++){
		if (pri(i))prime[tot++] =i;
	}
	for (int i=1;i<=70;i++){
		int temp = i;
		int sta =0;
		for (int j=0;j<tot;j++){
			int now =0;
			while (temp%prime[j]==0)now++,temp/=prime[j];
			if(now&1)sta+=bas[j];
		}
		status[i] =sta;
	}
}
void input(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
}
void solve(){
	dp[0][0]=1;
	int k=1;
	for (int i=1;i<=70;i++,k^=1){
		if (!cnt[i]){
			k^=1;
			continue;
		}
		memset(dp[k],0,sizeof dp[k]);
		int delta = bas[cnt[i]-1];
		int nowsta = status[i];
		for (int sta=0;sta<(1<<19);sta++){
			int newsta = nowsta^sta;
			dp[k][newsta]=(dp[k][newsta]+1LL*dp[k^1][sta]*delta%ZSC)%ZSC;
			dp[k][sta] = (dp[k][sta]+1LL*dp[k^1][sta]*delta%ZSC)%ZSC;
		}
	}
	cout<<(dp[k^1][0]-1+ZSC)%ZSC<<endl;
}
int main(){
	init();
	input();
	solve();
	return 0;
}