#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#include <ext/pb_ds/assoc_container.hpp> //  . 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;

ll prec_sun[300000];

typedef __gnu_pbds::tree<
int,
__gnu_pbds::null_type,
less<int>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>
ordered_set;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	prec_sun[0] = 0, prec_sun[1] = 1;
	for (int i=2; i < 300000; ++i) {
		prec_sun[i] = prec_sun[i-2] + (ll) i;
	}

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i=0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
	}

	vector<int> pos(n);
	for (int i=0;i<n;++i) pos[v[i]] = i;

	set<int> L, R;
	int middle = -1;
	ll lsum = 0, rsum = 0;

	ordered_set kek;

	ll I = 0;

	for (int i=0; i < n; ++i) {
		int p = pos[i];
		if (middle == -1) {
			if (!L.size()) {
				middle = p;
			}
			else{
				auto it = L.end();
				it--;
				int A = (*it);

				it = R.begin();
				int B = (*it);
				if (p > A && p < B) {
					middle = p;
				}
				else if (p < A) {
					lsum -= A;
					lsum += p;
					middle = A;
					L.erase(L.find(A));
					L.insert(p);
				}
				else{
					rsum -= B;
					rsum += p;
					middle = B;
					R.erase(R.find(B));
					R.insert(p);
				}
			}
		}
		else{
			int A = middle, B = p;
			if (A > B) swap(A, B);
			if (!L.size()) {
				lsum += A, rsum += B;
				L.insert(A), R.insert(B);
			}
			else{
				auto it = L.end();
				it--;
				int C = (*it);

				it = R.begin();
				int D = (*it);
				if (B < C) {
					L.insert(A), L.insert(B);
					L.erase(L.find(C));
					R.insert(C);
					rsum += C;
					lsum -= (-C+A+B);
				}
				else if (A > D) {
					R.insert(A), R.insert(B);
					R.erase(R.find(D));
					L.insert(D);
					lsum += D;
					rsum -= (-D+A+B);
				}
				else{
					lsum += A, rsum += B;
					L.insert(A), R.insert(B);
				}
			}
			middle = -1;
		}

		ll Q = rsum - lsum;
		ll len = i+1;
		Q -= (len/2);
		Q -= prec_sun[max(0, i-1)];

		kek.insert(pos[i]);
		int T = kek.order_of_key(pos[i]);
		I += i - T;
		cout << Q+I << " ";
	}


}