#include<bits/stdc++.h>
using namespace std;
int n,k,x;vector<int>a;
map<vector<int>,int>M;
int main(){
	cin>>n>>k>>x;a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());M[a]=0;
	
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i+=2)a[i]^=x;
		sort(a.begin(),a.end());
		//for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
		if(M[a]>=1 && (k-M[a])%((j+1)-M[a])==0){
			vector<int>P=a;
			cout<<P[n-1]<<' '<<P[0]<<endl;return 0;
		}
		M[a]=j+1;
	}
	cout<<a[n-1]<<' '<<a[0]<<endl;
	return 0;
}