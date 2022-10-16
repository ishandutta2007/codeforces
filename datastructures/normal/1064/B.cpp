#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int t,a;
signed main(){
	cin>>t;
	while(t--){
		cin>>a;
		int aa=a,s=0;
		while(aa)s+=aa%2,aa/=2;
		cout<<(1<<s)<<endl;
	}
	return 0;
}