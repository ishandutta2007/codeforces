#include <bits/stdc++.h>
using namespace std;
int a[1004]; 
int main(){
	int n;
	cin>>n;
	vector <int> ans;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;){
		int j;
		for (j=i+1;j<n && a[j]==a[j-1]+1;j++);
		ans.push_back(j-i);
		i=j; 
	}
	cout<<ans.size()<<"\n";
	for (int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	return 0;
}