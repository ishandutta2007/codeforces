#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


const int N=205;
int n, k;
int x[N];
int y[N];

pair<int, int> dp[N][N];
bool che[N][N];
int ar;

int wh(int i, int j, int k){
	return (abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[j]*y[i]-x[k]*y[j]-x[i]*y[k]));
}

pair<int, int>sol(int i, int j){
	if(i==j){
		return {0, 0};
	}
	if(che[i][j]){
		return dp[i][j];
	}
	che[i][j]=1;
	dp[i][j]={0, 0};
	for(int mid=i+1; mid<j; mid++){
		pair<int, int>le=sol(i, mid);
		pair<int, int>ri=sol(mid, j);
		int area=wh(i, mid, j);
		int ex=area+le.s+ri.s;
		int re=le.f+ri.f;
		if(ex>=ar){
			re++;
			ex=0;
		}
		dp[i][j]=max(dp[i][j], {re,ex});
	}
	return dp[i][j];
}



bool fu(int mid){
	ar=mid;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			che[i][j]=0;
		}
	}
	pair<int, int>u=sol(0, n-1);
	if(u.f>=k+1){
		return 1;
	}
	else{
		return 0;
	}
}

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	
	int lo=0;
	int hi=1e18;
	int ans=0;
	
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(fu(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}