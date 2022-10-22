#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
int n,m;
int a[maxn];
int main()
{
	int i,j;
	cin>>n;
	int cnt1=0,cnt0=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0) cnt1++;
		else if(a[i]<0) cnt0++;
	} 
	if(cnt1>=(n+1)/2) cout<<1;
	else if(cnt0>=(n+1)/2) cout<<-1;
	else cout<<0;
	return 0;
}