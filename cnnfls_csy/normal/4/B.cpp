#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
int n,m,i,j,ht[35],lt[35],sum,ti[35],mx,mi,x;
bool ok=0;
int main()
{
	cin>>n>>sum;
	for (i=1;i<=n;i++) 
	{
		cin>>lt[i]>>ht[i];
		mx+=ht[i];
		mi+=lt[i];
		ti[i]=lt[i];
	}
	if (mx>=sum&&mi<=sum)
	{
		cout<<"YES"<<endl;
		sum-=mi;
		for (i=1;i<=n;i++)
		{
			x=min(ht[i]-lt[i],sum);
			sum-=x;
			ti[i]+=x;
			cout<<ti[i]<<' ';
		}
	}
	else cout<<"NO";
	return 0;
}