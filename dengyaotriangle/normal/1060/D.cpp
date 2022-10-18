#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

int n;
int a[maxn],b[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	long long ans=n;
	for(int i=1;i<=n;i++) ans+=max(a[i],b[i]);
	cout<<ans;
    return 0;
}