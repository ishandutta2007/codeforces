#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
int n,a[105];
signed main(){
	cin>>n;
	int val=1;
	for (int i=2;i<=n;i++){
		cout<<"? ";
		for (int j=1;j<n;j++)cout<<i<<' ';
		cout<<1<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		if (x>0)val=i;
	}
	a[n]=val;
	for (int i=1;i<val;i++){
		cout<<"? ";
		for (int j=1;j<n;j++)cout<<val+1-i<<' ';
		cout<<1<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		a[x]=i;
	}
	for (int i=val+1;i<=n;i++){
		cout<<"? ";
		for (int j=1;j<n;j++)cout<<1<<' ';
		cout<<i+1-val<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		a[x]=i;
	}
	cout<<"! ";
	for (int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}