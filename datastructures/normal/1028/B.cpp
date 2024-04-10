#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	int len=n/9+100;
	for (int i=1;i<=len;i++)cout<<'9';
	for (int i=1;i<len;i++)cout<<'0';
	cout<<'1'<<endl;
	for (int i=1;i<=len;i++)cout<<'9';
	cout<<endl;
	return 0;
}