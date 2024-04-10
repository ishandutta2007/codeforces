#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int TOUR = 1<<18, MAX = TOUR;

struct node {
	int minn, maxx, prop;
	ll sum;
} t[2*TOUR];

void Propagiraj(int pos, int polsz)
{
	if (!t[pos].prop)
		return;

	for (int i=2*pos; i<=2*pos+1; i++) {
		t[i].minn = t[i].maxx = t[i].prop = t[pos].prop;
		t[i].sum = (ll) polsz * t[pos].prop;
	}

	t[pos].prop = 0;
}

void Stavi(int pos, int lo, int hi, int begin, int end, int val)
{
	if (lo >= end || hi <= begin || t[pos].minn >= val)
		return;
	if (lo >= begin && hi <= end) {
		if (t[pos].maxx <= val) {
			t[pos].minn = t[pos].maxx = t[pos].prop = val;
			t[pos].sum = (ll) (hi - lo) * val;
			return;
		}
	}

	assert(pos < TOUR);
	Propagiraj(pos, (hi - lo) / 2);
	Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
	Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
	t[pos].sum = t[2*pos].sum + t[2*pos+1].sum;
	t[pos].minn = min(t[2*pos].minn, t[2*pos+1].minn);
	t[pos].maxx = max(t[2*pos].maxx, t[2*pos+1].maxx);
}

ll Vrati(int pos, int lo, int hi, int begin, int end)
{
	if (lo >= end || hi <= begin)
		return 0;
	if (lo >= begin && hi <= end)
		return t[pos].sum;

	Propagiraj(pos, (hi - lo) / 2);
	return Vrati(2*pos+0, lo, (lo+hi)/2, begin, end) +
				 Vrati(2*pos+1, (lo+hi)/2, hi, begin, end);
}
int p[MAX];
int pref[MAX], suf[MAX];
vector <int> Poz[MAX];
vector <int> Djel[MAX], PozDj[MAX];
int n;

void GenPref(int polje[MAX])
{
	int ima[MAX];
	int mx = 0;
	memset(ima, 0, sizeof ima);

	for (int i=0; i<n; i++) {
		for (auto it : Djel[i])
			if (ima[it]++)
				mx = max(mx, it);

		polje[i] = mx;
	}
}

int main()
{
	scanf("%d", &n);

	for (int i=0; i<n; i++) {
		scanf("%d", &p[i]);
		Poz[p[i]].push_back(i);
	}

	for (int i=1; i<MAX; i++) {
		vector <int> T;
		for (int j=i; j<MAX; j+=i) {
			for (int k=0; k<2 && k<(int) Poz[j].size(); k++)
				T.push_back(Poz[j][k]);
			for (int k=(int) Poz[j].size()-1; k>=2 && k>=(int) Poz[j].size()-2; k--)
				T.push_back(Poz[j][k]);
		}

		sort(T.begin(), T.end());
		for (int j=0; j<2 && j<(int) T.size(); j++)
			Djel[T[j]].push_back(i);

		for (int j=(int) T.size()-1; j>=2 && j>=(int) T.size()-2; j--)
			Djel[T[j]].push_back(i);

		PozDj[i] = T;
	}

	GenPref(pref);
	reverse(Djel, Djel + n);
	GenPref(suf);
	reverse(Djel, Djel + n);
	reverse(suf, suf + n);

	for (int i=0; i<n; i++)
		Stavi(1, 0, TOUR, 0, i, suf[i]);

	int ima[MAX];
	memset(ima, 0, sizeof ima);
	ll rje = 0;

	for (int i=0; i<n; i++) {
		rje += Vrati(1, 0, TOUR, i, n);
		for (auto it : Djel[i]) {
			Stavi(1, 0, TOUR, i+1, PozDj[it].back(), it);
			if (ima[it]++)
				Stavi(1, 0, TOUR, i+1, TOUR, it);
		}
	}

	printf("%lld\n", rje);

	return 0;
}