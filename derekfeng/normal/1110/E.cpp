#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v1,v2;
int a[100004],b[100004];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)v1.push_back(a[i]-a[i-1]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=1;i<n;i++)v2.push_back(b[i]-b[i-1]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	puts(a[0]==b[0]&&b[n-1]==a[n-1]&&v1==v2?"Yes":"No");
}