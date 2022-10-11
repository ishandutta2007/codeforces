#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int Backet = 500;
long long A[509], B[509], S[509], C[250009], mod = 998244353;
set<pair<int, int>> Set[200009];

void init() {
	for (int i = 0; i < 509; i++) { A[i] = 0; B[i] = 0; S[i] = 0; }
	for (int i = 0; i < 509; i++) C[i] = 0;
	for (int i = 0; i < 509; i++) Set[i].clear();
}

void refresh(int pos) {
	for (int i = Backet * pos; i < Backet * (pos + 1); i++) {
		C[i] *= A[pos]; C[i] += B[pos];
		C[i] %= mod;
	}
	S[pos] = 0; for (int i = Backet * pos; i < Backet * (pos + 1); i++) S[pos] += C[i];
	S[pos] %= mod;
	A[pos] = 1; B[pos] = 0;
}

void add_minor(int l, int r) {
	int v1 = l / Backet;
	for (int i = l; i < r; i++) { S[v1]++; C[i]++; }
}

void mul_minor(int l, int r) {
	int v1 = l / Backet;
	for (int i = l; i < r; i++) { C[i] *= 2; while (C[i] >= mod) C[i] -= mod; }
	S[v1] = 0; for (int i = v1 * Backet; i < (v1 + 1) * Backet; i++) { S[v1] += C[i]; if (S[v1] >= mod) S[v1] -= mod; }
}

long long sum_minor(int l, int r) {
	int v1 = l / Backet; long long rem = 0;
	for (int i = l; i < r; i++) { rem += C[i]; }
	return rem % mod;
}

void add(int l, int r) {
	//  [l, r)  add
	int v1 = l / Backet, v2 = r / Backet;
	if (v1 == v2) {
		refresh(v1); add_minor(l, r);
	}
	else {
		refresh(v1); add_minor(l, (v1 + 1) * Backet);
		refresh(v2); add_minor(v2 * Backet, r);
		for (int i = v1 + 1; i < v2; i++) { B[i]++; S[i] += Backet; }
	}
}

void multiply(int l, int r) {
	//  [l, r)  mul
	int v1 = l / Backet, v2 = r / Backet;
	if (v1 == v2) {
		refresh(v1); mul_minor(l, r);
	}
	else {
		refresh(v1); mul_minor(l, (v1 + 1) * Backet);
		refresh(v2); mul_minor(v2 * Backet, r);
		
		for (int i = v1 + 1; i < v2; i++) {
			A[i] *= 2; while (A[i] >= mod) A[i] -= mod;
			B[i] *= 2; while (B[i] >= mod) B[i] -= mod;
			S[i] *= 2; while (S[i] >= mod) S[i] -= mod;
		}
	}
}

long long getsum(int l, int r) {
	int v1 = l / Backet, v2 = r / Backet;
	if (v1 == v2) {
		refresh(v1);
		return sum_minor(l, r);
	}
	else {
		long long ans = 0;
		refresh(v1); ans += sum_minor(l, (v1 + 1) * Backet);
		refresh(v2); ans += sum_minor(v2 * Backet, r);
		for (int i = v1 + 1; i < v2; i++) ans += S[i];
		return ans % mod;
	}
}

void query(int l, int r, int x) {
	vector<pair<int, int>> vec;

	while (true) {
		auto itr = Set[x].lower_bound(make_pair(l, 0));
		if (Set[x].begin() != itr) itr--;
		if (Set[x].end() != itr && (*itr).second < l - 1) itr++;

		if (itr == Set[x].end() || (*itr).first >= r + 2) break;
		vec.push_back(*itr);
		Set[x].erase(itr);
	}
	
	if (vec.size() == 0) {
		add(l, r + 1);
		Set[x].insert(make_pair(l, r));
	}

	else {
		for (int i = 0; i < vec.size(); i++) {
			int cl = vec[i].first, cr = vec[i].second;
			cl = max(cl, l); cr = min(cr, r);
			if (cl <= cr) multiply(cl, cr + 1);
		}
		if (l < vec[0].first) add(l, vec[0].first);
		if (vec[vec.size() - 1].second < r) add(vec[vec.size() - 1].second + 1, r + 1);

		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i].second + 1 <= vec[i + 1].first - 1) {
				add(vec[i].second + 1, vec[i + 1].first);
			}
		}

		Set[x].insert(make_pair(min(l, vec[0].first), max(r, vec[vec.size() - 1].second)));
	}
}

long long N, Q, ty[200009], l[200009], r[200009], x[200009];

vector<long long> solve_Jury() {
	vector<long long>ans, Z(N + 2, 0);
	vector<vector<bool>> ZZ(N + 2, vector<bool>(N + 2, false));

	for (int i = 0; i < Q; i++) {
		if (ty[i] == 1) {
			for (int j = l[i]; j <= r[i]; j++) {
				if (ZZ[j][x[i]] == false) { ZZ[j][x[i]] = true; Z[j]++; Z[j] %= mod; }
				else { Z[j] *= 2; Z[j] %= mod; }
			}
		}
		if (ty[i] == 2) {
			long long ret = 0;
			for (int j = l[i]; j <= r[i]; j++) {
				ret += Z[j]; ret %= mod;
			}
			ans.push_back(ret);
		}
	}
	return ans;
}

vector<long long> solve_Output() {
	vector<long long>s;
	for (int i = 0; i < 509; i++) A[i] = 1;
	for (int i = 0; i < Q; i++) {
		if (ty[i] == 1) {
			query(l[i], r[i], x[i]);
		}
		if (ty[i] == 2) {
			s.push_back(getsum(l[i], r[i] + 1));
		}
	}
	return s;
}

void random_generate() {
	init();
	N = 10; Q = 30;
	for (int i = 0; i < Q; i++) {
		ty[i] = rand() % 2 + 1;
		if (ty[i] == 1) {
			l[i] = rand() % N + 1; r[i] = rand() % N + 1; x[i] = rand() % N + 1;
			if (l[i] > r[i]) swap(l[i], r[i]);
		}
		if (ty[i] == 2) {
			l[i] = rand() % N + 1; r[i] = rand() % N + 1;
			if (l[i] > r[i]) swap(l[i], r[i]);
		}
	}
}

int Debug = 1;

int main() {
	if (Debug == 1) {
		cin >> N >> Q;
		for (int i = 0; i < Q; i++) {
			scanf("%lld", &ty[i]);
			if (ty[i] == 1) scanf("%lld%lld%lld", &l[i], &r[i], &x[i]);
			if (ty[i] == 2) scanf("%lld%lld", &l[i], &r[i]);
		}
		vector<long long> E = solve_Output();
		for (int i = 0; i < E.size(); i++) printf("%lld\n", E[i]);
		return 0;
	}
	else {
		for (int i = 1; i <= 1000000; i++) {
			random_generate();
			vector<long long> J1 = solve_Jury();
			vector<long long> J2 = solve_Output();

			if (J1 != J2) {
				cout << "Wrong Answer on Test #" << i << endl;
				cout << "Jury = {"; for (int j = 0; j < J1.size(); j++) { if (j) cout << ", "; cout << J1[j]; } cout << "}" << endl;
				cout << "Outp = {"; for (int j = 0; j < J2.size(); j++) { if (j) cout << ", "; cout << J2[j]; } cout << "}" << endl;
				cout << endl;
				cout << N << " " << Q << endl;
				for (int j = 0; j < Q; j++) {
					if (ty[j] == 1) cout << ty[j] << " " << l[j] << " " << r[j] << " " << x[j] << endl;
					if (ty[j] == 2) cout << ty[j] << " " << l[j] << " " << r[j] << endl;
				}
				cout << endl;
			}
		}
	}
	return 0;
}