#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100004];
void sol(){
	vector<int>v1,v2,v3,v4;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i&1)v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i&1)v3.push_back(a[i]);
		else v4.push_back(a[i]);
	}
	sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end()),sort(v3.begin(),v3.end()),sort(v4.begin(),v4.end());
	if(v1==v3&&v2==v4)puts("YES");
	else puts("NO");
}
int main(){
	cin>>T;
	while(T--)sol();
}