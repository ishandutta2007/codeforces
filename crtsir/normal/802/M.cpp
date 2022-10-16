#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x,y;
	long long tt=0;
	cin>>x>>y;
	int a[x];
	for(int i=0;i<x;i++)
		cin>>a[i];
	sort(a,a+x);
	for(int i=0;i<y;i++)
		tt+=a[i];
	cout<<tt;
}