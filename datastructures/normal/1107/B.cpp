#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int t,n,k;
signed main(){
	cin>>t;
	while(t--){
		cin>>k>>n;
		cout<<9*(k-1)+n<<endl;
	}
	return 0;
}