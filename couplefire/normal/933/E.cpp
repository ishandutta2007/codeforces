#include<bits/stdc++.h>
using namespace std;
using INT=long long;
const int NN=372727;
int a[NN],val[NN],b[NN];
INT dp[NN][2];
vector <int> ANS;
void sol(int k){
	int mn=min(a[k],a[k+1]);
	if(mn==0) return;
	ANS.push_back(k);
	a[k]-=mn;a[k+1]-=mn;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i),b[i]=a[i];
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i];
		if(i>1) dp[i][0]=min(dp[i][0],min(dp[i-2][1],dp[i-2][1])+max(a[i],a[i-1]));
		dp[i][1]=dp[i-1][0];
	}
	int st=n,fl=0;
	if(dp[n][1]<=dp[n][0]) fl=1;
	while(st){
		if(fl) st--,fl=0;
		else {
			if(dp[st][0]==dp[st-1][0]+b[st]) sol(st-1),sol(st),st--;
			else if(dp[st][0]==dp[st-1][1]+b[st]) sol(st),sol(st-1),st--,fl=1;
			else if(dp[st][0]==dp[st-2][0]+max(b[st],b[st-1])) sol(st-1),sol(st-2),sol(st),st-=2,fl=0;
			else sol(st-1),sol(st-2),sol(st),st-=2,fl=1;
		}
	}
	cout<<ANS.size()<<endl;
	for(int v:ANS) printf("%d\n",v);
	return 0;
}