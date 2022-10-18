#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

long long n,m;
long long x[maxn];

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	long long cd=0;
	for(int i=0;i<n;i++){
		long long ans=x[i]/m;
		long long ls=x[i]%m;
		cd+=ls;
		ans+=cd/m;
		cd=cd%m;
		cout<<ans<<' ';
	}
	return 0;
}