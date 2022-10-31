#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int main() {
	fio;
	typedef long long ll;
	ll k, d, t;
	cin >> k >> d >> t;
	double on_time = k;
	double off_time = (d-k%d)%d;
	double cycle = on_time + off_time;
	double on_speed = 1.0/t;
	double off_speed = 0.5/t;

	double cycle_cook = on_speed * on_time + off_speed * off_time;

	ll full_cycles = ll(1.0/cycle_cook);

	double ans = full_cycles * cycle;

	double remaining = 1.0 - full_cycles * cycle_cook;
	if(remaining <= on_time * on_speed) {
		ans += remaining / on_speed;
	} else {
		ans += on_time;
		remaining -= on_time * on_speed;
		ans += remaining / off_speed;
	}
	cout << setprecision(12) << fixed << ans << "\n";
}