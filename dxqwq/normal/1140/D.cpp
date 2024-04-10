#include<bits/stdc++.h>
using namespace std;
int qwq(int a,int b) { if(a>b) return b; else return a;}
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=2; i<n; i++) ans+=i*(i+1);
	cout<<ans;
	return 0;
}