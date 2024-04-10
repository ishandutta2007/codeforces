#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int dd;
ll cnt[(1 << 10) + 7][11][66][2];

ll calc(int mask, int ww, int len, int type){
	if (len == 0){
		return (mask == 0);
	}
	if (cnt[mask][ww][len][type] != -1) return cnt[mask][ww][len][type];
	ll ans = 0;
	for (int x = 0; x < ww; x++){
		int mm = mask;
		if (!(x == 0 && type == 0)) mm ^= (1 << x);
		int tt = type;
		if (x != 0) tt = 1;
		ans += calc(mm, ww, len - 1, tt);
	}
	cnt[mask][ww][len][type] = ans;
	return ans;
}

ll func(ll x){
	vector<int> t;
	while(x){
		t.pub(x % dd);
		x /= dd;
	}
	reverse(all(t));
	ll ans = 0;

	int mask = 0;

	for (int i = 0; i < t.size(); i++){
		for (int j = 0; j < t[i]; j++){
			if (i == 0 && j == 0) ans += calc(mask, dd, (int)t.size() - i - 1, 0);
			else ans += calc(mask ^ (1 << j), dd, (int)t.size() - i - 1, 1);
		}
		mask ^= 1 << t[i];
	}

	if (mask == 0) ans++;

	return ans;
}

int main(){ 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 7 + (1 << 10); i++) for (int j = 0; j < 11; j++) for (int s = 0; s < 66; s++) cnt[i][j][s][0] = -1, cnt[i][j][s][1] = -1;
    int tt;
    cin >> tt;
    while(tt--){
    	ll l, r;
    	cin >> dd >> l >> r;
    	cout << func(r) - func(l - 1) << "\n";
    }
}