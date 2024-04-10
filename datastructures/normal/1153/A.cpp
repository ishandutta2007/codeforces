#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,s,d,ans=2e9,id,t;
signed main(){
	cin>>n>>t;
	for (int i=1;i<=n;i++){
		cin>>s>>d;
		while(s<t)s+=d;
		if (ans>s)ans=s,id=i;
	}
	cout<<id<<endl;
	return 0;
}