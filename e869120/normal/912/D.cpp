#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

long long H, W, R, K, A[200009], B[200009], cnt[200009], ret;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>>Q;

int main() {
	cin >> H >> W >> R >> K;
	for (long long i = 0; i < H; i++) A[i] = min({ H - R + 1, R, i + 1, H - i });
	for (long long i = 0; i < W; i++) B[i] = min({ W - R + 1, R, i + 1, W - i });
	sort(A, A + H); reverse(A, A + H);
	sort(B, B + W); reverse(B, B + W);

	for (int i = 0; i < H; i++) { Q.push(make_pair(A[i] * B[0], i)); cnt[i]++; }

	for (int i = 0; i < K; i++) {
		ret += Q.top().first; int pos = Q.top().second; Q.pop();
		if (cnt[pos] < W) {
			Q.push(make_pair(A[pos] * B[cnt[pos]], pos));
			cnt[pos]++;
		}
	}
	printf("%.12Lf\n", 1.0L*ret / ((H - R + 1)*(W - R + 1)));
	return 0;
}