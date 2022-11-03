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
typedef pair<int, int> pii;

const int module = 1e9+7;

typedef unsigned int uint;

uint n,k;
uint ip[111111];

uint buffer[4];

uint getIp(uint * buffer)
{
	return buffer[3]+buffer[2]*256+buffer[1]*65536+buffer[0]*16777216;
}

void getBuf(uint ip)
{
	uint a[4];
	for (int i=0; i<4; i++)
	{
		a[i] = ip%256;
		ip /= 256;
	}
	for (int i=3; i>=0; i--)
	{
		cout << a[i];
		if (i!=0)cout << '.';
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
//	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n >> k;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<4; j++)
		{
			cin >> buffer[j];
			cin.ignore();
		}
		ip[i] = getIp(buffer);
	}
	sort(ip, ip+n);

	uint mask = (1 << 31);
	for (int i=31; i>0; i--)
	{
		int c=1;
		for (int j=1; j<n; j++)
			if ((ip[j]&mask)!=(ip[j-1]&mask))
				c++;
		if (c==k)
		{
			getBuf(mask);
			return 0;
		}
		mask += (1 << (i-1));
	}
	cout << -1 << endl;
	return 0;
}