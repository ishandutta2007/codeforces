#include<iostream>
#include<algorithm>
#include<deque>
#include<set>
#include<vector>
#include<utility>

using namespace std;

const int MAX = 1e8;

int k, n[4], t[4];
int g[4];
deque<int>	q[4];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < 3; i++)	cin >> n[i];
	for (int i = 0; i < 3; i++)	cin >> t[i];
	g[0] = k;

	int i;
	for (i = 0; i < MAX; i++){
		if (g[0] + g[1] + g[2] + q[0].size() + q[1].size() + q[2].size() == 0)	break;
		for (int j = 2; j >= 0; j--)
			while (q[j].size() && q[j].front() == i)
				q[j].pop_front(), g[j + 1]++;

		for (int j = 0; j < 3; j++){
			int x = min(g[j], n[j] - (int)q[j].size());
			g[j] -= x;
			while (x--)
				q[j].push_back(i + t[j]);
		}
	}
	cout << i - 1 << endl;
	return	0;	
}