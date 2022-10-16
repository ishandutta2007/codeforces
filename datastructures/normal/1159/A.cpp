#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,ans;
string x;
signed main(){
	cin>>n>>x;
	for (int i=0;i<x.size();i++)
		if (x[i]=='-')ans--,ans=max(ans,0);
		else ans++;
	cout<<ans<<endl;
	return 0;
}