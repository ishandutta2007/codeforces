#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int module = 1e9+7;

int n;
vector<int> t,c,q;

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	cin >> n;
	t.resize(n);
	c.resize(n);
	q.resize(n);
	for (int i=0; i<n; i++)
		cin >> t[i] >> c[i];
	int last;
	int qsize,msize,size,lf;
	msize = qsize = size = 0;
	lf = 0;
	int time=0;
	for (int i=0; i<n; i++)
	{
		msize = max(msize, size);
		int dl = t[i]-time;
		while (dl && size)
		{
			if (q[lf] <= dl)
			{
				time += q[lf];
				last = time;
				dl -= q[lf];
				size -= q[lf];
				lf++;
			}else
			{
				time += dl;
				last = time;
				q[lf] -= dl;
				size -= dl;
				dl = 0;
			}
		}
		size += c[i];
		q[qsize] = c[i];
		qsize++;
		time = t[i];
	}
	msize = max(msize, size);
	int dl = 1e9;
	while (dl && size)
		if (q[lf] <= dl)
		{
			time += q[lf];
			last = time;
			dl -= q[lf];
			size -= q[lf];
			lf++;
		}else
		{
			time += dl;
			last = time;
			q[lf] -= dl;
			size -= dl;
			dl = 0;
		}

	cout << last << " " << msize << endl;
	return 0;
}