#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
ULL __seed = 912606991;
unsigned int oadnrm()
{
	__seed = __seed * 0x41C64E6Du + 0x6073u;
	return __seed & 0xffffffffu;
}
const int N(1111111);
ULL hsh[N];
int fac[N], o[N];
int modulo(1e9 + 7);
vector<int> vec[N];
bool cmp(int x, int y) {
	return hsh[x] < hsh[y];
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(0); i < n; i++) {
		ULL cur(oadnrm() * 0x100000000ull + oadnrm());
		int x;
		scanf("%d", &x);
		for(int j(0); j < x; j++) {
			int y;
			scanf("%d", &y);
			hsh[y] += cur;
			vec[y].push_back(i);
		}
	}
	for(int i(1); i <= m; i++)
		o[i] = i;
	sort(o + 1, o + 1 + m, cmp);
	for(int i(1); i <= m; i++) {
		if(!((hsh[o[i]] == hsh[o[i + 1]]) == (vec[o[i]] == vec[o[i + 1]]))) {
			for(int j(0); j < (int)vec[o[i]].size(); j++) {
				printf("%d!", vec[o[i]][j]);
			}
			for(int j(0); j < (int)vec[o[i + 1]].size(); j++) {
				printf("%d?", vec[o[i + 1]][j]);
			}
		}
	}
	map<ULL, int> mp;
	for(int i(1); i <= m; i++) {
		//cout << hsh[i] << endl;
		mp[hsh[i]]++;
	}
	int ans(1);
	fac[0] = 1;
	for(int i(1); i <= m; i++) {
		fac[i] = (long long)i * fac[i - 1] % modulo;
	}
	for(map<ULL, int>::iterator itr(mp.begin()); itr != mp.end(); itr++) {
		ans = (long long)ans * fac[itr->second] % modulo;
	}
	cout << ans << endl;
}