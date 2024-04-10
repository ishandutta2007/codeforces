#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;
const long long modl=1000000007;

long long C[maxn][maxn];
int k;
int c[maxn];
long long cur;
long long ans=1;

int main(){ 
	C[0][0]=1;
	C[1][0]=1;
	C[1][1]=1;
	for(int i=2;i<maxn;i++){
		C[i][0]=1; 
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%modl;
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>c[i];
	}
	cur=c[0];
	for(int i=1;i<k;i++){
		ans*=C[cur+c[i]-1][c[i]-1];
		ans=ans%modl;
		cur+=c[i];
	}
	cout<<ans;
	return 0;
}