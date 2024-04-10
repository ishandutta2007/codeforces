#include <bits/stdc++.h>
using namespace std;
int n,a[103];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort (a,a+n);
	vector <int> v1,v2;
	for (int i=0;i<n;i++)
		if (i%2==0) v1.push_back(a[i]);
		else v2.push_back(a[i]);  
	for (int i=0;i<v1.size();i++) cout<<v1[i]<<" ";
	for (int i=int(v2.size())-1;i>=0;i--) cout<<v2[i]<<" ";
}