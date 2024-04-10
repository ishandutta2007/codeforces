#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif

const int MAXN = 5e5+10;

bool served[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int q;
    cin >> q;
    priority_queue<pair<int,int>> pq;
    int at = 1;
    int id = 1;
    for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int m;
			cin >> m;
			pq.push({m, -id});
			id++;
		}
		else if (t == 2) {
			while (served[at]) at++;
			//assert(at < id);
			served[at] = true;
			cout << at << " ";
		}
		else {
			int x = -pq.top().second;
			while (served[x]) pq.pop(), x = -pq.top().second;
			served[x] = true;
			cout << x << " ";
		}
	}
	cout << "\n";
}