#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int mu[100005];
vector<int> divs[100005];
bool flg[100005];
ll ans;

int cnt[100005];
int stk[100005],len;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	scanf("%d",&N);
	while(N--){
		int ai;scanf("%d",&ai);
		flg[ai]=1;
		ans=max(ans,(ll)ai);
	}
	mu[1]=1;
	for(int i=1;i<=100000;i++){
		divs[i].push_back(i);
		for(int j=i+i;j<=100000;j+=i)
			flg[i]|=flg[j],mu[j]-=mu[i],divs[j].push_back(i);
	}
	for(int i=100000;i;i--)if(flg[i]){
		int K=0;
		for(int j=0;j<divs[i].size();j++)
			K+=cnt[divs[i][j]]*mu[divs[i][j]];
		while(K){
			if(gcd(stk[len],i)==1) ans=max(ans,1LL*stk[len]*i);
			for(int j=0;j<divs[stk[len]].size();j++){
				cnt[divs[stk[len]][j]]--;
				if(i%divs[stk[len]][j]==0) K-=mu[divs[stk[len]][j]];
			}
			len--;
		} 
		stk[++len]=i;
		for(int j=0;j<divs[stk[len]].size();j++)
				cnt[divs[stk[len]][j]]++;
	}
	printf("%lld\n",ans);
}