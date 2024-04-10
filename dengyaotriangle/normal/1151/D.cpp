#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

int n;
long long f[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long x,y;
		cin>>x>>y;
		ans+=y*n-x;
		f[i]=(x-y);
	}
	sort(f+1,f+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		ans+=f[i]*i;
	}
	cout<<ans;
    return 0;
}