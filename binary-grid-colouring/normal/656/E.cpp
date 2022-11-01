#include<bits/stdc++.h>
#defi\
ne REP(i,a,b) fo\
r(int i=a;i<=b;i++)
using namespace std;

int M[11][11]={0};

int main(){
	int n;
	cin>>n;
	REP(i,1,n)REP(j,1,n)cin>>M[i][j];
	REP(k,1,n)REP(i,1,n)REP(j,1,n)M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
	int ans=0;
	REP(i,1,n)REP(j,1,n)ans=max(ans,M[i][j]);
	cout<<ans<<endl;
	return 0;
}