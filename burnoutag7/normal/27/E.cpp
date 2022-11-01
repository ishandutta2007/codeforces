/******************
*  Writer: Oh no  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;

LL divs,ans;
int pri[]={2,3,5,7,11,13,17,19,23,29};

void dfs(int pos,LL n,int d,int pr){
	if(d==divs){
		ans=min(ans,n);
		return;
	}
	for(int i=1;i<=pr;i++){
		if(n>ans/pri[pos]) break;
		n*=pri[pos];
		if(divs%(d*(i+1))==0) dfs(pos+1,n,d*(i+1),i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>divs;
	ans=1e18;
	dfs(0,1,1,100);
	cout<<ans<<endl;
	
	return 0;
}