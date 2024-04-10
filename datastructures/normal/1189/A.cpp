#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
string a;
int n,num;
signed main(){
	cin>>n>>a;
	for (int i=0;i<a.size();i++)
		if (a[i]=='1')num++;
	if (num*2==a.size()){
		cout<<2<<endl;
		for (int i=0;i<a.size()-1;i++)cout<<a[i];cout<<' ';
		cout<<a[a.size()-1]<<endl;
	}
	else{
		cout<<1<<endl;
		cout<<a<<endl;
	}
	return 0;
}