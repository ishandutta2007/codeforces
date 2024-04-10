#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int t,a,b,c;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if ((a+b>=c-1)&&(a+c>=b-1)&&(b+c>=a-1))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}