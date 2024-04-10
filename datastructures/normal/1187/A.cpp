#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,n,a,b;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		int aa=a-(a+b-n);
		int bb=b-(a+b-n);
		cout<<max(aa,bb)+1<<endl;
	}
	return 0;
}