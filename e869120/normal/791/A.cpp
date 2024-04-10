#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;cin>>a>>b;
	int c=0;while(a<=b){a*=3;b*=2;c++;}
	cout<<c<<endl;
	return 0;
}