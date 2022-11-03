#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

ll n, a, b;

bool can(int val){
	if (val > min(a, b)) return 0;
	ll cnt = (a / val) + (b / val);
	return cnt >= n;
}

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a >> b;
	int vl = 1, vr = 1e9;
	while(vl + 1 < vr){
		int vm = (vl + vr) >> 1;
		if (can(vm))
			vl = vm;
		else
			vr = vm;
	}
	cout << vl;
}