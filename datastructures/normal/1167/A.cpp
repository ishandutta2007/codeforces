#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n;
string k;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		int flag=0;
		for (int i=0;i<k.size();i++)
			if (k[i]=='8'&&k.size()-i>=11)flag=1;
		if (flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}