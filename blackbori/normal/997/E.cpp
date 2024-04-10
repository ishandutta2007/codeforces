#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

vector <int> V;
int A[202020], B[202020], T[202020];
int L[202020], R[202020];
int X[202020], Y[202020], Z[202020];
ll AL[202020], AR[202020], K[202020], Q[202020];
int n, q;

void dnc(int s, int e, vector <int> &V)
{
	if(s == e){
		for(int &t: V) Q[t] = 1;
		AL[s] = AR[s] = 1;
		return;
	}

	vector <int> VL, VR, S;
	vector <pii> PL, PR, PB;
	int i, j, m, l, r, x, y, t, b, f;
	ll c;
	
	m = s + e >> 1;

	auto add = [&](int t){
		for(; f && x > A[t]; ){
			x --;
			if(B[x] < s || e < B[x]) f = 0;
			S.push_back(B[x]);
		}
		for(; f && y < A[t]; ){
			y ++;
			if(B[y] < s || e < B[y]) f = 0;
			S.push_back(B[y]);
		}
		for(; f && r < t; ) S.push_back(++ r);
		for(; f && l > t; ) S.push_back(-- l);
	};

	l = r = m + 1;
	x = y = A[m + 1];
	f = 1; S.clear();

	for(; f && l > s; ){
		S.push_back(-- l);
		for(; f && !S.empty(); ){
			t = S.back(); S.pop_back();
			add(t);
		}
		if(f) PL.emplace_back(l, r);
	}

	l = r = m;
	x = y = A[m];
	f = 1; S.clear();

	for(; f && r < e; ){
		S.push_back(++ r);
		for(; f && !S.empty(); ){
			t = S.back(); S.pop_back();
			add(t);
		}
		if(f) PR.emplace_back(l, r);
	}

	for(int &t: V){
		if(R[t] <= m) VL.push_back(t);
		else if(L[t] > m) VR.push_back(t);
	}

	dnc(s, m, VL); dnc(m + 1, e, VR);

	for(i = t = l = r = c = 0; i < PL.size(); i ++){
		for(f = 0; l < PR.size() && PR[l].second <= PL[i].second; l ++) f = 1;
		for(; r < PR.size() && PR[r].first > PL[i].first; r ++) f = 1;
		if(r < PR.size() && PR[r] == PL[i]) PB.push_back(PL[i]);
		if(f) t = i; c += max(0, r - l); K[i] = c;
		X[i] = l, Y[i] = r - 1, Z[i] = t;
	}

	for(int &t: V){
		if(L[t] <= m && m < R[t]){
			auto comp = [&](pii &p, int t){
				return L[t] <= p.first && p.second <= R[t];
			};
			l = lower_bound(PL.begin(), PL.end(), t, comp) - PL.begin();
			r = lower_bound(PR.begin(), PR.end(), t, comp) - PR.begin();
			b = lower_bound(PB.begin(), PB.end(), t, comp) - PB.begin();
			Q[t] = AR[L[t]] + AL[R[t]] + l + r - b; l --; r --;

			if(l >= 0 && r >= 0){
				if(X[l] <= min(r, Y[l])){
					Q[t] += (ll)(l - Z[l] + 1) * (min(r, Y[l]) - X[l] + 1);
				}
				if(Z[l]) Q[t] += K[Z[l] - 1];
			}
		}
	}

	for(i = m, j = l = r = c = 0; i >= s; i --){
		for(; j < PL.size() && PL[j].first >= i; j ++){
			for(; l < PR.size() && PR[l].second < PL[j].second; l ++);
			for(; r < PR.size() && PR[r].first >= PL[j].first; r ++);
			c += r - l;
		}
		AR[i] += AR[m + 1] + c;
	}

	for(i = m + 1, j = l = r = c = 0; i <= e; i ++){
		for(; j < PR.size() && PR[j].second <= i; j ++){
			for(; l < PL.size() && PL[l].first > PR[j].first; l ++);
			for(; r < PL.size() && PL[r].second <= PR[j].second; r ++);
			c += r - l;
		}
		AL[i] += AL[m] + c;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i;

	cin >> n;

	for(i = 1; i <= n; i ++){
		cin >> A[i];
		B[A[i]] = i;
	}

	cin >> q;

	for(i = 1; i <= q; i ++){
		cin >> L[i] >> R[i];
		V.push_back(i);
	}

	dnc(1, n, V);

	for(i = 1; i <= q; i ++){
		cout << Q[i] << "\n";
	}

	return 0;
}