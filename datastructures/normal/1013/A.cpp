#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,x,s1,s2;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>x,s1+=x;
	for (int i=1;i<=n;i++)cin>>x,s2+=x;
	if (s1>=s2)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}