/*

Code for problem D by cookiedoth
Generated 18 Sep 2022 at 11.03 PM
The Moon is Waning Crescent (39% of Full)


       .
      ":"
    ___:____     |"\/"|
  ,'        `.    \  /
  |  O        \___/  |
~^~^~^~^~^~^~^~^~^~^~^~^~

z_z
>_<
\_()_/

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#include <array>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()
#define vi vector<int>
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

vi get_k_cnt(int N){
    int num_left = N;
    int kc_sum_max = 0;
    for(int kc_sum = 1; ; kc_sum++){
        //c = 1, 3, 5, ...
        int on_diagonal = (kc_sum+1)/2;
        if(on_diagonal <= num_left){
            num_left-=on_diagonal;
            continue;
        }
        else{
            kc_sum_max = kc_sum;
            break;
        }
    }


    vi res(kc_sum_max+5, 0);

    for(int i = 0; i <= kc_sum_max; i++){
        if(num_left > 0){
            
            int k = kc_sum_max-i;
            int c = kc_sum_max-k;
            if(c < 0 || c % 2 != 1) continue;
            num_left--;
            res[k]++;
        }
        
    }

    // cout << "kc_max: " << kc_sum_max << " " << num_left << "\n";
    // for(int i = 0; i < sz(res); i++){
    //     cout << "k = " << i << "\n";
    //     cout << res[i] << "\n";
    // }

    for(int k = 0; k < sz(res); k++){
        {
            int easy_kc_sum = kc_sum_max-1;
            int c_max = easy_kc_sum-k;
            if(c_max >= 1){
                if(c_max % 2 == 0) c_max--;
                res[k]+=(c_max+1)/2;
            }
        }
    }

    return res;
}

int n, R;
vector<int> rows, pref_rows;
const int RADIUS = 15;

void prepare() {
	cin >> n;
	ll S = 0, n1 = n;
	for (ll s = 1; ; ++s) {
		ll cnt_s = (s - 1) / 2 + 1;
		ll r_cnt = min(n1, cnt_s);
		n1 -= r_cnt;
		S += s * r_cnt;
		if (n1 == 0) {
			break;
		}
	}
	cout << S << '\n';
	rows = get_k_cnt(n);
	// n = 12;
	// rows = {3, 3, 2, 2, 1, 1};
	R = rows.size();
	pref_rows.resize(R + 1);
	for (int i = 0; i < R; ++i) {
		pref_rows[i + 1] = pref_rows[i] + rows[i];
	}
}

void solve() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int pos;
		cin >> pos;
		pos--;
		int mid = lower_bound(all(pref_rows), pos) - pref_rows.begin();
		int l = max(0, mid - RADIUS);
		int r = min(R - 1, mid + RADIUS);
		int id = pos - pref_rows[l];
		// cerr << "l, r, id " << l << ' ' << r << ' ' << id << '\n';
		ll L = 0, R = 1e18;
		while (L < R) {
			ll mid = (L + R) >> 1;
			// cerr << "mid = " << mid << '\n';
			ll cnt = 0;
			for (ll i = l; i <= r; ++i) {
				ll max_div = mid / (1LL << (i - l));
				max_div = (max_div + 1) / 2;
				chkmin(max_div, (ll)rows[i]);
				cnt += max_div;
			}
			// cerr << "cnt = " << cnt << '\n';
			if (cnt > (ll)id) {
				R = mid;
			} else {
				L = mid + 1;
			}
		}
		ll k = 0, c = L;
		while (c % 2 == 0) {
			c /= 2;
			k++;
		}
		cout << k + c + l << '\n';
	}
}

signed main() {
	fast_io();
	prepare();
	solve();
}