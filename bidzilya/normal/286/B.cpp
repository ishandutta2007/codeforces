#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int n;
vector<int> b;

int main()
{
	scanf("%d",&n);
	b.resize(2*n);
	for (int i=1; i<=n; i++)
		b[i]=i;
	int l=1,r=n;
	for (int i=2; i<=n; i++)
	{
		int x=b[l];
		int j=l;
		l++;r++;
		while (j<r)
		{
			j=min(j+i,r);
			swap(x,b[j]);
		}
	}
	for (int i=l; i<=r; i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}