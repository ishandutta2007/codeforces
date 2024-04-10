#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool work[n+1][n+1];
	bool othwork[n+1];
	set<int> kek;
	bool bruh=true;
	othwork[n]=true;
	int ans=INT_MAX;
	for(int i=n-1;i>=0;i--){
		if(kek.count(arr[i]))bruh=false;
		kek.insert(arr[i]);
		othwork[i]=bruh;
		if(othwork[i]){
			ans=min(ans,i);
		}
	}
	set<int> se;
	for(int i=0;i<n;i++){
		se.insert(arr[i]);
		if(se.size()!=i+1){
			for(int j=n;j>i;j--){
				work[i][j]=false;
			}
		}
		else {
			set<int> sec;
			bool can=true;
			work[i][n]=true;
			for (int j = n - 1; j > i; j--) {
				if(sec.count(arr[j])||se.count(arr[j]))can=false;
				sec.insert(arr[j]);
				work[i][j]=can;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(work[i][j]){
				ans=min(ans,j-i-1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}