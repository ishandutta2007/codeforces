#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define fff(i, f, t) for (i = f; i < t; ++i)
#define ff(i, n) fff(i, 0, n)

struct sector {
	int index;
	int fragment;
};

bool cmpSector (sector sectorA, sector sectorB) {
	return sectorA.fragment < sectorB.fragment;
}

int main (void) {
	ios_base::sync_with_stdio(0);

	int n;
	vector <sector> hdd;

	cin >> n;
	hdd.resize(n);

	int i, k, m;

	ff (i, n) {
		hdd[i].index = i;
		cin >> hdd[i].fragment;
	}

	sort(hdd.begin(), hdd.end(), cmpSector);

	long long int result = 0;
	fff (i, 1, n) {
		result += abs(hdd[i].index - hdd[i - 1].index);
	}

	cout << result;

	return 0;
}