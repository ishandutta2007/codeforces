#include <bits/stdc++.h>
using namespace std;
int n,a[10000];
vector <int> ans;
bool ok(int d){
	for(int i = 0; i + d < n; ++i)
		if(a[i + 1] - a[i] != a[i + d + 1] - a[i + d])
			return false;
	return true;
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; ++i)
		cin>>a[i];
	for(int i = 1; i <= n; ++i)
		if(ok(i))
			ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
}