/* 	* In the name of GOD 
	Emtehana tamoom shod alan vagt sag code :D */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a_arabi_bekhoon[N], dp_shimi_khoonet_kam_shode[N], n;

int bs_sag_to_doroos_madrese(int i_defaii_yadet_nare, int x_maaref_ro_mafhoomi_bekhoon) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a_arabi_bekhoon[mid] > a_arabi_bekhoon[i_defaii_yadet_nare] - x_maaref_ro_mafhoomi_bekhoon) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a_arabi_bekhoon[i];
	}
	dp_shimi_khoonet_kam_shode[0] = 20;
	cout << 20 << '\n';
	for (int i_defaii_yadet_nare = 1; i_defaii_yadet_nare < n; i_defaii_yadet_nare++) {
		dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare] = dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare - 1] + 20;
		int mn = dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare - 1] + 20;
		if (a_arabi_bekhoon[i_defaii_yadet_nare] < 90) {
			mn = min(mn, 50);
		}
		if (a_arabi_bekhoon[i_defaii_yadet_nare] < 1440) {
			mn = min(mn, 120);
		}
		if (a_arabi_bekhoon[i_defaii_yadet_nare] >= 90) {
			mn = min(mn, (bs_sag_to_doroos_madrese(i_defaii_yadet_nare, 90) == 0 ? 0 : dp_shimi_khoonet_kam_shode[bs_sag_to_doroos_madrese(i_defaii_yadet_nare, 90) - 1]) + 50);
		}
		if (a_arabi_bekhoon[i_defaii_yadet_nare] >= 1440)
			mn = min(mn, (bs_sag_to_doroos_madrese(i_defaii_yadet_nare, 1440) == 0 ? 0 : dp_shimi_khoonet_kam_shode[bs_sag_to_doroos_madrese(i_defaii_yadet_nare, 1440) - 1]) + 120);
		dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare] = mn;
		cout << dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare] - dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare - 1] << '\n';
//		cout << dp_shimi_khoonet_kam_shode[i_defaii_yadet_nare] << '\n';
	}
}