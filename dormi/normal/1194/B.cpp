#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		int n,m;
		cin>>n>>m;
		int row[n]={ };
		int col[m]={ };
		string arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			for(int j=0;j<m;j++){
				if(arr[i][j]=='*') {
					row[i] += 1;
					col[j] += 1;
				}
			}
		}
		int checkminus=0;
		int high=0;
		for(int i=0;i<n;i++){
			high=max(high,row[i]);
		}
		int high2=0;
		for(int i=0;i<m;i++){
			high2=max(high2,col[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]=='.'&&row[i]==high&&col[j]==high2) {
					checkminus=1;
				}
			}
		}
		printf("%d\n",(n-high)+(m-high2)-checkminus);
	}
	return 0;
}