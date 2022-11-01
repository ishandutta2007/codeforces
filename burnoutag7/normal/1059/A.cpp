/******************
*  Writer: BD747  *
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

int n,len,a;
int t[100005],l[100005];
int ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>len>>a;
	
	for(int i=1;i<=n;i++){
		cin>>t[i]>>l[i];
		ans+=(t[i]-t[i-1]-l[i-1])/a;
	}
	ans+=(len-t[n]-l[n])/a;
	
	cout<<ans<<endl;
	
	return 0;
}