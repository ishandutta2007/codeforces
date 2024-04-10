#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size

ll N, A, cf, cm, M, cost, cmin, ind, num, ans=0, cmin1, ind1, num1, need[100000];
int code[100000], ansv[100000];
vector<pii> ori;
vi s;

ll get (int k) {
	return A-s[N-k];
}

int main() {
	cin >> N >> A >> cf >> cm >> M;
	F0R(i,N) {
		int x;
		scanf("%d",&x), ori.pb(mp(x,i));
	}
	sort(ori.b(),ori.e());
	F0R(i,N) code[i] = ori[i].s, s.pb(ori[i].f);

	while (cost+get(ind+1) <= M && ind < N) ind ++, cost += get(ind);

	if (ind == N) {
		cout << cf*N+cm*A << endl; 
		F0R(i,N) cout << A << " ";
		return 0;
	}

	FOR(i,1,N) need[i] = need[i-1]+i*(s[i]-s[i-1]);
	num = 1, cmin = s[0];
	while (need[num] <= M-cost && num+1+ind <= N) cmin = s[num], num++;
	cmin += (M-cost-need[num-1])/num;
	ans = cf*ind+cm*cmin;
	ind1 = ind, cmin1 = cmin, num1 = num;
	
	while (ind > 0) {
		cost -= get(ind), ind --;
		cmin = s[num-1];
		while (need[num] <= M-cost && num+ind+1 <= N) cmin = s[num], num++;
		cmin += (M-cost-need[num-1])/num;
		if (cf*ind+cm*cmin > ans) {
			ans = cf*ind+cm*cmin;
			ind1 = ind, cmin1 = cmin, num1 = num;
		}
	}
	
	cout << ans << endl;
	F0R(i,N) {
		int k;
		if (i < num1) k = cmin1;
		else if (N-1-i<ind1) k = A;
		else k = ori[i].f;
		ansv[code[i]] = k;
	}
	F0R(i,N) cout << ansv[i] << " ";
	return 0;
}