#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n, m, t;
	cin>>n>>m>>t;
	char arr[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	bool b=false;
	bool booly[n][m];
	long long int d[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			booly[i][j]=false;
			d[i][j]=5000;
		}
	}
	queue<pair<int, int>>q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i+1<n && arr[i][j]==arr[i+1][j]){
				q.push({i, j});
				booly[i][j]=true;
				d[i][j]=0;
				b=true;
				continue;
			}
			if(i-1>=0 && arr[i][j]==arr[i-1][j]){
				q.push({i, j});
				booly[i][j]=true;
				d[i][j]=0;
				b=true;
				continue;
			}
			if(j+1<m && arr[i][j]==arr[i][j+1]){
				q.push({i, j});
				booly[i][j]=true;
				d[i][j]=0;
				b=true;
				continue;
				
			}
			if(j-1>=0 && arr[i][j]==arr[i][j-1]){
				q.push({i, j});
				booly[i][j]=true;
				d[i][j]=0;
				b=true;
				continue;
			}
		}
	}
	
	while(!q.empty()){
		int i=q.front().first;
		int j=q.front().second;
		q.pop();
		if(i+1<n && d[i+1][j]>1+d[i][j]){
			q.push({i+1, j});
			d[i+1][j]=1+d[i][j];
		}
		if(i-1>=0 && d[i-1][j]>1+d[i][j]){
			q.push({i-1, j});
			d[i-1][j]=1+d[i][j];
		}
		if(j+1<m && d[i][j+1]>1+d[i][j]){
			q.push({i, j+1});
			d[i][j+1]=1+d[i][j];
		}
		if(j-1>=0 && d[i][j-1]>1+d[i][j]){
			q.push({i, j-1});
			d[i][j-1]=1+d[i][j];
		}
	}
	
	for(int g=0; g<t; g++){
		long long int i, j, q;
		cin>>i>>j>>q;
		i--;
		j--;
		if(!b){
			cout<<arr[i][j]<<endl;
			continue;
		}
		if(d[i][j]>=q){
			cout<<arr[i][j]<<endl;
			continue;
		}
		q=q-d[i][j];
		if(q%2==0){
			cout<<arr[i][j]<<endl;
			continue;
		}
		else{
			cout<<int('1' - arr[i][j])<<endl;
			continue;
		}
	}
	return 0;
}