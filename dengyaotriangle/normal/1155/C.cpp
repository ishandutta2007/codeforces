#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n,m;
long long x[maxn];

long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	long long gc=x[2]-x[1];
	for(int i=3;i<=n;i++){
		gc=gcd(gc,x[i]-x[i-1]);
	}
	for(int i=1;i<=m;i++){
		long long cc;cin>>cc;
		if(gc>=cc&&(gc%cc==0)){
			cout<<"YES"<<endl<<x[1]<<' '<<i;
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}