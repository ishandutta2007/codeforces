#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL x,y,z,a,b,c;
int main(){
		cin>>x>>y>>z;
		a=x+y;b=a/z;
		if(x/z+y/z==b)c=0;
		else c=min(min(x%z,z-x%z),min(y%z,z-y%z));
		cout<<b<<" "<<c<<endl;
	return 0;
}