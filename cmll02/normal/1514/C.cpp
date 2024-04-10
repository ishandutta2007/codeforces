#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,a[100009],tot=0;
	long long ml=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)if(__gcd(i,n)==1)a[tot++]=i,ml=ml*i%n;
	if(ml!=1)tot--;
	cout<<tot<<"\n";
	for(int i=0;i<tot;i++)cout<<a[i]<<" ";
	return 0;
}