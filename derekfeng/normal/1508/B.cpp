#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e18;
ll K;
int T,n,bit[100004],ans[100004];
void sol(){
	cin>>n>>K;
	ll num1=1;
	for(int i=1;i<n;i++){
		num1=min((num1+num1),M);
	}
	if(num1<K){
		puts("-1");
		return;
	}
	K--;
	int cnt=0;
	for(int i=1;i<=n;i++)bit[i]=0;
	for(int i=0;i<64;i++)if(n-1-i>0)bit[n-1-i]=(((1ll<<i)&K)>0);
	for(int i=1;i<=n;){
		int j=i;
		while(bit[j]>0)j++;
		for(int k=j;k>=i;k--)ans[++cnt]=k;
		i=j+1;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";puts("");
}
int main(){
	cin>>T;
	while(T--)sol();
}