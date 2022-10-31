#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int> > q;

int k, n1, t1, n2, t2, n3, t3;
int waitTo2 = 0, waitTo3 = 0, have2 = 0, have3 = 0;

int main() {
	scanf("%d %d %d %d %d %d %D", &k, &n1, &n2, &n3, &t1, &t2, &t3);
	int waitTo1 = max(0, k - n1);
	for(int i = 1; i <= k && i <= n1; i++) {
		q.push(make_pair(-t1, 1));
	}
	
	int ans = 0;
	
	while(!q.empty()) {
		pair<int, int> tmp = q.top();
		q.pop();
		ans = -tmp.first;
		if (tmp.second == 1) {
			if (have2 < n2) {
				q.push(make_pair(tmp.first - t2, 2));
				have2++;
			} else {
				waitTo2++;
			}
			
			if (waitTo1) {
				waitTo1--;
				q.push(make_pair(tmp.first - t1, 1));
			}
			
		} else if (tmp.second == 2) {
			if (have3 < n3) {
				q.push(make_pair(tmp.first - t3, 3));
				have3++;
			} else {
				waitTo3++;
			}
			
			if (waitTo2) {
				waitTo2--;
				q.push(make_pair(tmp.first - t2, 2));
			} else {
				have2--;
			}
		} else {
			if (waitTo3) {
				waitTo3--;
				q.push(make_pair(tmp.first - t3, 3));
			} else {
				have3--;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}