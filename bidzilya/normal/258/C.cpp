

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;	

const int module=1e9+7;
const int S=1e5;

int binPow(int base, int power)
{
	if (power==0)
		return 1;
	if (power%2==1)
		return (1LL*base*binPow(base, power-1))%module;
	int res=binPow(base, power/2);
	return (1LL*res*res)%module;
}

vector<int> c,q;
int ans,n,cn;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	c.resize(S+10);
	q.resize(S+10);
	for (int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		c[1]++;
		c[x+1]--;
	}
	int sum=0;
	for (int i=1; i<=S; i++)
	{
		sum += c[i];
		c[i] = sum;
	}
	ans=1;
	for (int i=2; i<=S; i++)
		if (c[i] > 0)
		{
			cn=0;
			for (int j=1; 1LL*j*j<=i; j++)
				if (i%j==0)
				{
					q[cn]=j;
					cn++;
					if (j*j!=i)
					{
						q[cn]=i/j;
						cn++;
					}
				}
			sort(q.begin(), q.begin()+cn);
			int sum1=1,sum2=1;
			for (int j=cn-1; j>=0; j--)
			{
				int power=c[q[j]];
				if (j+1 < cn)
					power -= c[q[j+1]];
				sum1 = (1LL*sum1*binPow(j+1, power))%module;
			}
			for (int j=cn-2; j>=0; j--)
			{
				int power=c[q[j]];
				if (j+2 < cn)
					power -= c[q[j+1]];
				sum2 = (1LL*sum2*binPow(j+1, power))%module;
			}
			ans = (ans + (sum1-sum2+module)%module)%module;
		}
	cout << ans << endl;
	return 0;
}