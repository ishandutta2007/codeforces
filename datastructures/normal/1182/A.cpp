#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n;
signed main(){
	cin>>n;
	if (n%2==1)cout<<0<<endl;
	else cout<<(1<<(n/2))<<endl;
	return 0;
}