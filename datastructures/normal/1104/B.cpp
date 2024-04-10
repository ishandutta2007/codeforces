#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
string s;
int ans,a[100005],top;
signed main(){
	cin>>s;
	memset(a,-1,sizeof(a));
	for (int i=0;i<s.size();i++){
		a[++top]=s[i]-'a';
		if (a[top]==a[top-1])top-=2,ans++;
	}
	if (ans%2==0)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}