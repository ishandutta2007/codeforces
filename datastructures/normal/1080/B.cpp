#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t;
inline int work(int x){
	if (x%2==0)return x/2;
	return x/2-x;
} 
signed main(){
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<work(r)-work(l-1)<<endl;
	}
	return 0;
}