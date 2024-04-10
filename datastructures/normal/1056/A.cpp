#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,len,x,book[105];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>len;
		for (int j=1;j<=len;j++)cin>>x,book[x]++;
	}
	for (int i=1;i<=100;i++)
		if (book[i]==n)cout<<i<<' ';
	cout<<endl;
	return 0;
}