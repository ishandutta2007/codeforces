#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int n,l,r,ans,now=1;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n>>l>>r;
	cout<<(1<<l)-1+n-l<<' '<<(1<<r)-1+(n-r)*((1<<(r-1)))<<endl;
	return 0;
}