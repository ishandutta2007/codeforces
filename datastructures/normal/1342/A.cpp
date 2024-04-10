#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int t,x,y,a,b;
signed main(){
	cin>>t;
	while(t--){
		cin>>x>>y>>a>>b;
		b=min(b,2*a);
		cout<<min(x,y)*b+(max(x,y)-min(x,y))*a<<endl;
	}
	return 0;
}