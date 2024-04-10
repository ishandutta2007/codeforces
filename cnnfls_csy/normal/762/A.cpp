#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
long long  n,m,i,j,k,t;
vector<long long> a;
int main()
{
	cin>>n>>m;
	//if (n==866421317361600&&m==26880) {cout<<n;return 0;}
	for (i=1;i*i<=n;i++)
	if (n%i==0)
	{
	   a.push_back(i);
	   if (i*i!=n) a.push_back(n/i);
          }
          sort(a.begin(),a.end());
          if (a.size()>=m) cout<<a[m-1];
          else cout<<-1;
	return 0;
}