#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=998244353;
const int N=2e5+5;
int po[N];
int arr[N];

int n, m;
int base[35];
vector<int>v;
int cnt[36];
int dp[36][36][(1<<12)];

void dfs(int ind, int val){
	if(ind==(v.size())){
		cnt[(__builtin_popcountll(val))]++;
		return;
	}
	dfs(ind+1, val);
	dfs(ind+1, val^v[ind]);
}
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	po[0]=1;
	
	for(int i=1; i<N; i++){
		po[i]=(2*po[i-1])%MOD;
	}
	
	int k=0;
	for(int i=0; i<n; i++){
		int val=arr[i];
		for(int j=0; j<35; j++){
			if(base[j]){
				if((val&(1LL<<j))){
					val=val^base[j];
				}
				continue;
			}
			if(!base[j] && (val&(1LL<<j))){
				base[j]=val;
				k++;
				break;
			}
		}
	}
	
	
	for(int i=0; i<35; i++){
		if(!base[i]){
			continue;
		}
		for(int j=0; j<=i-1; j++){
			if((base[j]&(1LL<<i))){
				base[j]=base[j]^base[i];
			}
		}
	}
	
	
	
	if(k<=23){
		for(int i=0; i<35; i++){
			if(base[i]){
				v.pb(base[i]);
			}
		}
		
		dfs(0, 0);
		for(int i=0; i<=m; i++){
			int num=(cnt[i]*po[n-k])%MOD;
			cout<<num<<" ";
		}
		return 0;
	}
	else{
		
		bool th[35];
		for(int i=0; i<35; i++){
			th[i]=0;
		}
		vector<int>nth;
		int ind[35];
		
		for(int i=0; i<35; i++){
			if(base[i]){
				th[i]=1;
			}
			else{
				ind[i]=nth.size();
				nth.pb(i);
			}
		}
		
		vector<int>vec;
		for(int i=0; i<35; i++){
			if(!base[i]){
				continue;
			}
			
			int mask=0;
			for(int j=0; j<35; j++){
				if(th[j]){
					continue;
				}
				if((base[i]&(1LL<<j))){
					mask+=(1LL<<(ind[j]));
				}
			}
			vec.pb(mask);
		}
		int sz=vec.size();
		
		dp[0][0][0]=1;
		for(int i=0; i<sz; i++){
			for(int j=0; j<=35; j++){
				for(int msk=0; msk<(1<<12); msk++){
					if(j+1<=35){
						dp[i+1][j+1][msk^vec[i]]=(dp[i+1][j+1][msk^vec[i]]+dp[i][j][msk])%MOD;
					}
					dp[i+1][j][msk]=(dp[i+1][j][msk]+dp[i][j][msk])%MOD;
				}
			}
		}
		for(int j=0; j<=35; j++){
			for(int msk=0; msk<(1<<12); msk++){
				if((j+(__builtin_popcountll(msk)))<=35){
					cnt[j+(__builtin_popcountll(msk))]=(cnt[j+(__builtin_popcountll(msk))]+dp[vec.size()][j][msk])%MOD;
				}
			}
		}
		for(int i=0; i<=m; i++){
			cout<<(cnt[i]*po[n-k])%MOD<<" ";
		}
		return 0;
	}
	
	return 0;
}