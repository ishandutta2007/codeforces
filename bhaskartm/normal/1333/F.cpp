#include <bits/stdc++.h>
using namespace std;
int sv[500005];
int main() {
	int n;
	cin>>n;
	for(int i=2; i<=n; i++){
		if(sv[i]!=0){
			continue;
		}
		for(int j=2*i; j<=n; j=j+i){
			if(sv[j]==0){
				sv[j]=i;
			}
		}
	}
	vector<int>v;
	for(int i=1; i<=n; i++){
		if(i==1 || sv[i]==0){
			v.push_back(1);
		}
		else{
			v.push_back(i/sv[i]);
		}
	}
	sort(v.begin(), v.end());
	for(int i=1; i<n; i++){
		cout<<v[i]<<" ";
	}
	return 0;
}