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
int mustUsed[10];
int used[10];
int pos[12];
int len;
vector<uint> ans;

void check()
{
	for (int i=0; i<10; i++)
		used[i]=0;
	for (int i=0; i<len; i++)
		used[pos[i]]=1;
	for (int i=0; i<10; i++)
		if (mustUsed[i] && !used[i] || !mustUsed[i] && used[i])
			return;
	uint x1,x2,x3,x4;
	for (int p1=0; p1<=2; p1++)
		for (int p2=p1+1; p2<=p1+3; p2++)
			for (int p3=p2+1; p3<=p2+3; p3++)
			{
				int l4 = len-p3-1;
				if (l4 > 3)continue;
				if (pos[0]==0 && p1!=0)continue;
				x1 = 0;
				for (int i=0; i<=p1; i++)
					x1 = x1*10+pos[i];
				if (x1 > 255)continue;
				if (pos[p1+1]==0 && p2!=p1+1)continue;
				x2=0;
				for (int i=p1+1; i<=p2; i++)
					x2 = x2*10+pos[i];
				if (x2 > 255)continue;
				if (pos[p2+1]==0 && p3!=p2+1)continue;
				x3=0;
				for (int i=p2+1; i<=p3; i++)
					x3 = x3*10+pos[i];
				if (x3 > 255)continue;
				if (pos[p3+1]==0 && l4!=1)continue;
				x4=0;
				for (int i=p3+1; i<len; i++)
					x4 = x4*10+pos[i];
				if (x4 > 255)continue;
				ans.push_back(x4+x3*256+x2*65536+x1*16777216);
			}
}

void go(int v)
{
	if (2*v >= len)
	{
		check();
		return;
	}
	for (int i=0; i<10; i++)
	{
		pos[v] = pos[len-v-1] = i;
		go(v+1);
	}
}	

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		mustUsed[x] = 1;
	}

	for (len = 4; len <= 12; len++)
		go(0);

	cout << ans.size() << endl;
	uint x1,x2,x3,x4;
	for (int i=0; i<ans.size(); i++)
	{
		x4 = ans[i]%256;
		ans[i] /= 256;
		x3 = ans[i]%256;
		ans[i] /= 256;
		x2 = ans[i]%256;
		ans[i] /= 256;
		x1 = ans[i];
		cout << x1 << '.' << x2 << '.' << x3 << '.' << x4 << endl;
	}
	return 0;
}