#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;
long long n,m,i,j,s,t;
string st;
long long makemax(long long n)
{
	long long s=0;
	for (i=1;i<=n/2;i++) s=s*10+7;
	for (i=n/2+1;i<=n;i++) s=s*10+4;
	return s;
}
int main()
{
	cin>>n;
	t=n;
	while (t)
	{
		m++;
		t/=10;
	}
	m+=(m&1);
	for (i=0;i<m/2;i++) st+="4";
	for (i=m/2;i<m;i++) st+="7";
	sscanf(st.c_str(),"%lld",&t);
	//cout<<m<<' '<<st<<' '<<t<<endl;
	if (makemax(m)<n) {m+=2;st="4"+st+"7";}
	do
	{
		sscanf(st.c_str(),"%lld",&t);
		if (t>=n) {cout<<t;return 0;}
	}
	while (next_permutation(st.begin(),st.end()));
	return 0;
}