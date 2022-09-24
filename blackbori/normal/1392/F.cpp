#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

ll H[1010101], A[1010101];
vector <pll> V;
ll n;

void insert(ll l, ll r)
{
	if(l > r) return;
	if(!V.empty() && V.back().second + 1 == l){
		V.back().second = r;
	}
	else V.emplace_back(l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i, t, h, x;

	cin >> n;

	for(i = 1; i <= n; i ++){
		cin >> H[i];
	}

	if(n == 1){
		cout << H[1] << "\n";
		return 0;
	}

	t = H[2] - H[1]; t >>= 1;
	H[2] -= t; H[1] += t;
	
	if(n == 2){
		cout << H[1] << " " << H[2] << "\n";
		return 0;
	}

	if(H[2] - H[1]){
		V.emplace_back(2, 2);
	}

	h = H[2];
	for(i = 3; i <= n; i ++){
		for(; h + 1 < H[i]; ){
//			cout << h << " " << H[i] << endl;
			if(V.empty() || V.back().second != i - 1){
				H[i] --; h ++;
				insert(i - 1, i - 1);
				continue;
			}

			auto [l, r] = V.back(); V.pop_back();

			if(l == 2){
				t = r - l + 2;
				x = (H[i] - h) / (t + 1);
				h += x; H[i] -= t * x;
				if(H[i] > h + 1){
					t = H[i] - h - 1; H[i] -= t;
					insert(l, l + t - 2);
					insert(l + t, r);
				}
				else insert(l, r);
			}
			else{
				t = r - l + 2;
				if(H[i] - t >= h + 1){
					H[i] -= t;
//					cout << "yeah" << i << " " << H[i] << " " << t << endl;
					insert(l - 1, r);
					h ++;
				}
				else{
					t = H[i] - h - 1; H[i] -= t;
					insert(l - 1, l + t - 2);
					insert(l + t, r);
				}
			}
		}

		if(h + 1 == H[i]) insert(i, i), h ++;

//		for(auto [l, r]: V) cout << l << " " << r << " / ";
//		cout << h << endl;
	}

	for(auto [l, r]: V){
		for(i = l; i <= r; i ++){
			A[i] = 1;
		}
	}
	for(i = 1; i <= n; i ++){
		A[i] += A[i - 1];
	}
	h -= A[n];

	for(i = 1; i <= n; i ++){
		cout << A[i] + h << " ";
	}
	cout << "\n";

	return 0;
}