//  228

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	
	int c=0;
	int sn=0;
	for(int i=0;i<t;i++){
		int a,b;
	    cin>>a>>b;
		sn-=a;
		sn+=b;
		c=max(c,sn);
	}
	cout<<c<<"\n";
	return 0;
}