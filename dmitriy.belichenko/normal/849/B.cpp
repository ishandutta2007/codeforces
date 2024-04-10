#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

const int N = 1e3;
pair <long long, long long> pts[N];
int good[N];

int main()
{
	::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		pts[i].fst = i;
		cin >> pts[i].snd;
	}
	random_shuffle(pts, pts + n);
	for (int i = 0; i < n && i < 5; ++i) {
		for (int j = i + 1; j < n; ++j) {
			long long x = pts[j].fst - pts[i].fst;
			long long y = pts[j].snd - pts[i].snd;
			int top = 0;
			for (int a = 0; a < n; ++a) {
				long long dx = pts[a].fst - pts[i].fst;
				long long dy = pts[a].snd - pts[i].snd;
				if (dx * y != dy * x) {
					good[top++] = a;
				}
			}
			if (top == 0) {
				continue;
			} else if (top == 1) {
				puts("Yes");
				return 0;
			} else {
				long long id1 = good[0], id2 = good[1];
				long long x3 = pts[id1].fst - pts[id2].fst;
				long long y3 = pts[id1].snd - pts[id2].snd;
				if (x3 * y != y3 * x) {
					continue;
				}
				bool ok = true;
				for (int a = 2; ok && a < top; ++a) {
					long long dx = pts[good[a]].fst - pts[id1].fst;
					long long dy = pts[good[a]].snd - pts[id1].snd;
					if (dx * y3 != dy * x3) {
						ok = false;
					}
				}
				if (ok) {
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}