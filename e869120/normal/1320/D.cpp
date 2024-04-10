#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long V[2];
long long power[2][1 << 18];

bool isprime(int pos) {
	for (int i = 2; i * i <= pos; i++) {
		if (pos % i == 0) return false;
	}
	return true;
}

long long Rand() {
	return (rand() % 32768) * 32768 + (rand() % 32768);
}

void init() {
	int cnt = 0;
	while (cnt < 2) {
		long long B = Rand() % 100000000 + 900000000;
		if (isprime(B) == true) {
			V[cnt] = B;
			cnt++;
		}
	}

	for (int i = 0; i < 2; i++) {
		power[i][0] = 1;
		for (int j = 1; j < (1 << 18); j++) power[i][j] = (3LL * power[i][j - 1]) % V[i];
	}
}

class RollingHash {
public:
	vector<long long> hash1;
	vector<long long> hash2;

	void init(string S) {
		hash1.resize(S.size() + 1, 0);
		hash2.resize(S.size() + 1, 0);
		for (int i = 1; i <= S.size(); i++) {
			hash1[i] = (3LL * hash1[i - 1] + (long long)(S[i - 1] - '0' + 1)) % V[0];
			hash2[i] = (3LL * hash2[i - 1] + (long long)(S[i - 1] - '0' + 1)) % V[1];
		}
	}
	pair<long long, long long> gethash(int cl, int cr) {
		long long V1 = (hash1[cr + 1] - hash1[cl] * power[0][cr - cl + 1] + V[0] * V[0]) % V[0];
		long long V2 = (hash2[cr + 1] - hash2[cl] * power[1][cr - cl + 1] + V[1] * V[1]) % V[1];
		return make_pair(V1, V2);
	}
};

int N; string S;
vector<int> T;
RollingHash C1, C2;

bool solve(int cl, int cr, int dl, int dr) {
	int pos1 = lower_bound(T.begin(), T.end(), cl) - T.begin();
	int pos2 = lower_bound(T.begin(), T.end(), cr) - T.begin();
	int pos3 = lower_bound(T.begin(), T.end(), dl) - T.begin();
	int pos4 = lower_bound(T.begin(), T.end(), dr) - T.begin();
	if (pos2 - pos1 != pos4 - pos3) return false;

	pair<long long, long long> F1, F2;
	if (cl % 2 == 0) F1 = C1.gethash(pos1, pos2 - 1); else F1 = C2.gethash(pos1, pos2 - 1);
	if (dl % 2 == 0) F2 = C1.gethash(pos3, pos4 - 1); else F2 = C2.gethash(pos3, pos4 - 1);
	if (F1 == F2) return true;
	return false;
}

int main() {
	init();
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') T.push_back(i);
	}

	string V1 = "", V2 = "";
	for (int i = 0; i < T.size(); i++) { if (T[i] % 2 == 0) V1 += "0"; else V1 += "1"; }
	for (int i = 0; i < T.size(); i++) { if (T[i] % 2 == 1) V2 += "0"; else V2 += "1"; }
	C1.init(V1); C2.init(V2);

	int Q; scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int a1, a2, a3; scanf("%d%d%d", &a1, &a2, &a3); a1--; a2--;
		bool I = solve(a1, a1 + a3, a2, a2 + a3);
		if (I == true) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}