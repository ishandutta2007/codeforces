#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

int n;
int a[N], s[N];
vector<pair<int, int> > answers;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + (a[i] == 1);
		//printf("%d\n", s[i]);
	}
	for(int t = 1; t <= n; t++) {
		int score[2] = {0}, start = 0, last;
		bool legal = true;
		while(start < n) {
			if (s[n] - s[start] < t && n - start - (s[n] - s[start]) < t) {
				legal = false;
				break;
			}
			int l = start, r = n;
			while(l < r) {
				int mid = (l + r) >> 1;
				if (s[mid] - s[start] >= t || mid - start - (s[mid] - s[start]) >= t) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			if (s[l] - s[start] >= t) {
				score[0]++;
				last = 0;
			} else {
				score[1]++;
				last = 1;
			}
			start = l;
		}
		//printf("%d %d %d %d\n", score[0], score[1], last, legal);
		if (legal && ((last == 0 && score[0] > score[1]) || (last == 1 && score[1] > score[0]))) {
			answers.push_back(make_pair(max(score[0], score[1]), t));
		}
	}
	sort(answers.begin(), answers.end());
	printf("%d\n", (int)answers.size());
	for(int i = 0; i < (int)answers.size(); i++) {
		printf("%d %d\n", answers[i].first, answers[i].second);
	}
	return 0;
}