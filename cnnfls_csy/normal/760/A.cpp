#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m,i,j,s;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	cin>>n>>m;
	m+=a[n]-1;
	while (m>0) {m-=7;s++;}
	cout<<s;
	return 0;
}