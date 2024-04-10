#include <bits/stdc++.h>

using namespace std;

void minup(int &a, int b) {
	a = min(a, b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	const int INF = (int) 1e9 + 7;
	
	int n, k;
	cin >> n >> k;
	vector<int> p(n), w(n);
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		w[p[i]] = i;
	}		
	
	vector<int> first_zero_bit((1 << k), -1);
	for (int x = 0; x < (1 << k); x++) {
		for (int i = 0; i <= k; i++) {
			if (!(x & (1 << i))) {
				first_zero_bit[x] = i;
				break;
			}
		}
	}
	vector<vector<int>> memo(n, vector<int> (k + 1, 0));
	for (int f = 0; f < n; f++) {
		for (int g = f; g <= min(n - 1, f + k); g++) {
			for (int x = 0; x < f; x++) {
				memo[f][g - f] += (w[x] > w[g]);
			}
		}
	}
	vector<vector<int>> min_inversions(n + 1, vector<int> ((1 << k), INF));
	min_inversions[0][0] = 0;
	
	for (int first_unplaced = 0; first_unplaced < n; first_unplaced++) {
		for (int placed_mask = 0; placed_mask < (1 << k); placed_mask++) {
			if (min_inversions[first_unplaced][placed_mask] == INF) {
				continue;
			}
			for (int guy = first_unplaced; guy <= min(n - 1, first_unplaced + k); guy++) {	
				int nw_first_unplaced, nw_placed_mask;
				
				if (guy == first_unplaced) {
					nw_first_unplaced = first_unplaced + 1 + first_zero_bit[placed_mask];
					nw_placed_mask = placed_mask >> (1 + first_zero_bit[placed_mask]);
				} else {
					nw_first_unplaced = first_unplaced;
				
					int id = guy - first_unplaced - 1;
					if (placed_mask & (1 << id)) {
						continue;
					}
					
					nw_placed_mask = placed_mask + (1 << id);
				}
						
				int invs = min_inversions[first_unplaced][placed_mask] + memo[first_unplaced][guy - first_unplaced];

				for (int bit = 0; bit < k; bit++) {
					if (placed_mask & (1 << bit)) {
						invs += (w[first_unplaced + 1 + bit] > w[guy]);
					}
				}
				minup(min_inversions[nw_first_unplaced][nw_placed_mask], invs);
			}
		}
	}
	cout << min_inversions[n][0] << "\n";
}