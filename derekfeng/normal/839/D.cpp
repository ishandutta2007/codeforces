#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n;
vector<int>v[1000004];
int x;
int num[1000004],pow2[200004],ans;
int res[1000004];
int main(){
	scanf("%d",&n);
	pow2[0]=1;
	for(int i=1;i<=n;i++)pow2[i]=pow2[i-1]*2%MOD;
	for(int i=1;i<=1e6;i++){
		for(int j=i;j<=1e6;j+=i)v[j].push_back(i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=0;j<v[x].size();j++)
			num[v[x][j]]++;
	}
	for(int i=1e6;i>=2;i--)if(num[i]>0){
		int val=1ll*pow2[num[i]-1]*num[i]%MOD;
		res[i]=(res[i]+val)%MOD;
		for(int j=v[i].size()-2;j>=0;j--)
			res[v[i][j]]=(res[v[i][j]]+MOD-res[i])%MOD;
		if(i>1)ans=(1ll*res[i]*i%MOD+ans)%MOD;
	}
	printf("%d",ans);
}