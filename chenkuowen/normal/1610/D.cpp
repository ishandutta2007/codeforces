#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7,N=5+2e5;
int pw2[N];
int solve(vector<int> a){
	if(a.empty()) return 0;
	vector<int> a0,a1;
	for(int i=0;i<a.size();++i){
		if(a[i]&1) a0.push_back(a[i]);
		else a1.push_back(a[i]/2);
	}
	int ans=0;
	if(a0.size()>0) ans=(ans+1ll*(pw2[a0.size()-1]-1)*pw2[a1.size()])%MOD;
	ans=(ans+solve(a1))%MOD;
	return ans;
}
int main(){
	pw2[0]=1; for(int i=1;i<N;++i) pw2[i]=2ll*pw2[i-1]%MOD;
	int n; scanf("%d",&n);
	vector<int> a;
	int cnt0=0,cnt1=0;
	for(int i=0;i<n;++i){
		int x; 
		scanf("%d",&x);
		if(x&1) cnt0++;
		else cnt1++,a.push_back(x/2);
	}
	int ans=1ll*(pw2[cnt0]+MOD-1)*pw2[cnt1]%MOD;
	printf("%d\n",(ans+solve(a))%MOD);
	return 0;
}