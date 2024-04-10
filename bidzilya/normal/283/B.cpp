#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

vector<int> a,nx,used;
vector<long long> ic;
int n;
int version=0;

void nx_step(int &tnx,long long &tic)
{
	tic+=a[tnx];
	tnx+=a[tnx];
	if (tnx>n)
	{
		tnx=n+1;
		return;
	}
	tic += a[tnx];
	tnx -= a[tnx];
	if (tnx<=0)
		tnx=n+1;
}

void go(int v)
{
	used[v]=version;
	long long tic=0;
	int tnx=v;
	nx_step(tnx,tic);
	if (tnx!=n+1 && tnx!=1)
	{
		if (used[tnx]==version)
			nx[v]=0;
		else
		{
			if (!used[tnx])go(tnx);
			nx[v]=nx[tnx];
			ic[v]=tic+ic[tnx];
		}
	}else
	{
		nx[v]=tnx;
		ic[v]=tic;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	a.resize(n+1);
	nx.resize(n+1);
	ic.resize(n+1);
	used.resize(n+1);
	for (int i=2; i<=n; i++)
		cin >> a[i];
	
	for (int i=2; i<=n; i++)
		if (!used[i])
		{
			version++;
			go(i);
		}
	
	for (int i=1; i<n; i++)
	{
		a[1]=i;
		int tnx=1;
		long long tic=0;
		nx_step(tnx,tic);
		if (tnx==n+1)
			cout << tic << endl;
		else
		if (tnx==1)
			cout << -1 << endl;
		else
		if (nx[tnx]==n+1)
			cout << tic+ic[tnx] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}