#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> Rect;

#define F first
#define S second
#define A F.F
#define B F.S
#define C S.F
#define D S.S

const int MAXN = 2e5 + 10;
const int INF = (int)1e9 + 10;

int n;
Rect a[MAXN], tl[MAXN], tr[MAXN];

Rect inter(Rect a, Rect b){
	if (a.D == INF) return a;
	if (b.D == INF) return b;
	Rect ret;
	ret.A = max(a.A, b.A);
	ret.B = max(a.B, b.B);
	ret.C = min(a.C, b.C);
	ret.D = min(a.D, b.D);
	if (ret.A > ret.C) ret.D = INF;
	if (ret.B > ret.D) ret.D = INF;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].A >> a[i].B >> a[i].C >> a[i].D;
	tl[0] = a[0];
	for (int i = 1; i < n; i++)
		tl[i] = inter(tl[i-1], a[i]);
	tr[n-1] = a[n-1];
	for (int i = n-2; ~i; i--)
		tr[i] = inter(tr[i+1], a[i]);

	if (tl[n-2].D != INF)
		cout << tl[n-2].C << " " << tl[n-2].D << "\n";
	else if (tr[1].D != INF)
		cout << tr[1].C << " " << tr[1].D << "\n";
	else{
		for (int i = 1; i < n-1; i++){
			Rect temp = inter(tl[i-1], tr[i+1]);
			if (temp.D != INF){
				cout << temp.C << " " << temp.D << "\n";
				return 0;
			}
		}
	}
	return 0;
}