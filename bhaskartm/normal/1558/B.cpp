#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=4e6+5;

int n, MOD;

int dp1[N];//pre
int dp2[N];//div
int dpt[N];//total

int pre[N];

int add(int x, int y){
	return (x+y)%MOD;
}

int sub(int x, int y){
	return (x-y+MOD)%MOD;
}


 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>MOD;
	
	dpt[1]=1;
	pre[1]=1;
	
	for(int i=2; i<=n; i++){
		dp1[i]=pre[i-1];
		dp2[i]=add(dp2[i], dp2[i-1]);
		dp2[i]=add(1, dp2[i]);
		dpt[i]=add(dp1[i], dp2[i]);
		pre[i]=add(pre[i-1], dpt[i]);
		for(int j=2; j*i<=n; j++){
			dp2[j*i]=add(dp2[j*i], dpt[i]);
			dp2[j*i]=sub(dp2[j*i], dpt[i-1]);
		}
	}
	
	cout<<dpt[n]<<endl;
	return 0;
}