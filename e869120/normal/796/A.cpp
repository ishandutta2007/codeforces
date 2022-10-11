#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[100000];
int main() {
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int minx=1000000;
	for(int i=1;i<=n;i++){if(a[i]>=1 && a[i]<=k)minx=min(minx,abs(i-m));}
	cout<<minx*10<<endl;
	return 0;
}