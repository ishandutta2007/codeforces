#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
string a;
int x,num,n;
signed main(){
	cin>>x;
	cin>>a;
	for (int i=0;i<a.size();i++)
		if (a[i]=='8')num++;
		else n++;
	int ans=0;
	for (int i=1;i<=num;i++){
		ans=max(ans,min((n+num-i)/10,i));
	}
	cout<<ans<<endl;
	return 0;
}