#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int>m1[21][21];
map<long long int, long long int>m2[21][21];
int main() {
	long long int n, m, k;
	cin>>n>>m>>k;
	long long int arr[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	
	if(n==1 && m==1){
		if(arr[0][0]==k){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
		return 0;
	}
	m1[0][0][arr[0][0]]++;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==0 && j==0){
				continue;
			}
			if(i+j>=min(n, m)){
				continue;
			}
			if(i>0){
				for(auto it=m1[i-1][j].begin(); it!=m1[i-1][j].end(); it++){
					m1[i][j][(it->first)^arr[i][j]]+=(it->second);
				}
			}
			if(j>0){
				for(auto it=m1[i][j-1].begin(); it!=m1[i][j-1].end(); it++){
					m1[i][j][(it->first)^arr[i][j]]+=(it->second);
				}
			}
		}
	}
	
	m2[n-1][m-1][arr[n-1][m-1]]++;
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			if(i==n-1 && j==m-1){
				continue;
			}
			if(i+j<min(n, m)){
				continue;
			}
			if(i<n-1){
				for(auto it=m2[i+1][j].begin(); it!=m2[i+1][j].end(); it++){
					m2[i][j][(it->first)^arr[i][j]]+=(it->second);
				}
			}
			if(j<m-1){
				for(auto it=m2[i][j+1].begin(); it!=m2[i][j+1].end(); it++){
					m2[i][j][(it->first)^arr[i][j]]+=(it->second);
				}
			}
		}
	}
	
	
	long long int ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((i+j)!=(min(n, m)-1)){
				continue;
			}
			for(auto it=m1[i][j].begin(); it!=m1[i][j].end(); it++){
				if(i+1<n){
					ans+=((m2[i+1][j][k^(it->first)])*(it->second));;
				}
				if(j+1<m){
					ans+=((m2[i][j+1][k^(it->first)])*(it->second));
				}
			}
		}
	}
	cout<<ans;
	return 0;
}