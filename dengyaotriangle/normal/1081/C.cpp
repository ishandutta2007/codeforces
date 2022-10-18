#include<bits/stdc++.h>

using namespace std;

const long long modo=998244353ll;
const int maxn=2005;

long long c[maxn][maxn];
int main(){
	c[0][0]=1;
	c[1][0]=1;
	c[1][1]=1;
	for(int i=2;i<maxn;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%modo;
	}
	long long n,m,k;
	cin>>n>>m>>k;
	long long cp=c[n-1][k];
	cp=(cp*m)%modo;
	for(int i=1;i<=k;i++) cp=(cp*(m-1))%modo;
	cout<<cp;
	return 0;
}