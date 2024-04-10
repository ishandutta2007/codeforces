#include <bits/stdc++.h>
using namespace std;
int ed[45][45];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	if(a[0]!=b[0]){
		cout<<"No";
		return 0;
	}
	vector<int>v1;
	vector<int>v2;
	for(int i=1; i<n; i++){
		v1.push_back(a[i]-a[i-1]);
	}
	for(int i=1; i<n; i++){
		v2.push_back(b[i]-b[i-1]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(int i=0; i<v1.size(); i++){
		if(v1[i]!=v2[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}