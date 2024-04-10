#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=4005;
int n, k;
int val[N][N];
int cost[N][N];
int pre[N][N];
int dp_before[N];
int dp_cur[N];


void f(int l, int r, int optl, int optr){
	if(l>r){
		return;
	}
	int mid=(l+r)/2;
	pair<int, int>best={1e9, -1};
	for(int k=optl; k<=min(optr, mid); k++){
		best=min(best, {dp_before[k-1]+cost[k][mid], k});
	}
	dp_cur[mid]=best.f;
	int opt=best.second;
	f(l, mid-1, optl, opt);
	f(mid+1, r, opt, optr);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	char c;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			
			cin>>c;
			val[i][j]=c-'0';
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			pre[i][j]=val[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
		}
	}
	
	
	
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			cost[i][j]=pre[j][j]-pre[i-1][j]-pre[j][i-1]+pre[i-1][i-1];
		}
	}
	
	for(int i=1; i<=n; i++){
		dp_before[i]=1e9;
	}
	
	for(int i=1; i<=k; i++){
		f(1, n, 1, n);
		for(int i=1; i<=n; i++){
			dp_before[i]=dp_cur[i];
		}
	}
	cout<<(dp_before[n])/2;
	return 0;
}