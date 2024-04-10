#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int N = 111111;

int n, m, times[N];
set<pair<int, pair<int, int> > > s;
struct Event {
	int id, l, r;
	Event(int id, int l, int r) : id(id), l(l), r(r) {}
};

int operator <(const Event &a, const Event &b) {
	return a.l == b.l ? a.id < b.id : a.l < b.l;
}

vector<Event> events;

int answer[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		events.push_back(Event(i, a, b));
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &times[i]);
		events.push_back(Event(-i, a, b));
	}
	sort(events.begin(), events.end());
	for(int i = 0; i < (int)events.size(); i++) {
		if (events[i].id > 0) {
			set<pair<int, pair<int, int> > > :: iterator it = s.upper_bound(make_pair(events[i].r, make_pair(-1, -1)));
			if (it == s.end()) {
				printf("NO\n");
				//printf("%d\n", events[i].id);
				return 0;
			} else {
				pair<int, pair<int, int> > temp = *it;
				s.erase(it);
				answer[events[i].id] = temp.second.first;
				temp.second.second--;
				if (temp.second.second > 0) {
					s.insert(temp);
				}
			}
		} else {
			int id = -events[i].id;
			s.insert(make_pair(events[i].r, make_pair(id, times[id])));
		}
	}
	puts("YES");
	for(int i = 1; i <= n; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	return 0;
}