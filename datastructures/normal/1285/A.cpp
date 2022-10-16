#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,l,r;
string a;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n>>a;
	for (int i=1;i<=n;i++)
		if (a[i]=='L')l--;
		else r++;
	cout<<r-l+1<<endl;
	return 0;
}