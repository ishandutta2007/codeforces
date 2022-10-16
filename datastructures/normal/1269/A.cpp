#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int n;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	if (n==1)cout<<9<<' '<<8<<endl;
	else if (n%2==0)cout<<n+4<<' '<<4<<endl;
	else cout<<n+9<<' '<<9<<endl;
	return 0;
}