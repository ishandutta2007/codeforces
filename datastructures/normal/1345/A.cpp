#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n,m;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		if (n==1||m==1||n<3&&m<3)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}