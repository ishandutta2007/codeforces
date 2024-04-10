#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
#define F0R(i, a) for (int i=0; i<a; i++)
#define f first
#define s second

ll ans = 1000000000000000000;
int N,K;
pii x[100000], y[100000];
vi x1,x2,y11,y2;

ll query(int w1, int w2, int w3, int w4) {
	map<int,bool> done;
	F0R(i,w1) done[x1[i]] = 1;
	F0R(i,w2) done[x2[i]] = 1;
	F0R(i,w3) done[y11[i]] = 1;
	F0R(i,w4) done[y2[i]] = 1;
	w2 = N-1-w2, w4 = N-1-w4;
	while (done[x[w1].s]) w1++;
	while (done[x[w2].s]) w2--;
	while (done[y[w3].s]) w3++;
	while (done[y[w4].s]) w4--;
	ll t1 = max(1,(x[w2].f-x[w1].f+1)/2), t2 = max(1,(y[w4].f-y[w3].f+1)/2);
	return t1*t2;
}

main() {
	scanf("%d%d",&N,&K);
	F0R(i,N) {
		int z1,z2;
		scanf("%d%d%d%d",&x[i].f,&y[i].f,&z1,&z2);
		x[i].f += z1, y[i].f += z2, x[i].s = i, y[i].s = i;
	}
	sort(x,x+N), sort(y,y+N);
	F0R(i,K) x1.pb(x[i].s), x2.pb(x[N-1-i].s),y11.pb(y[i].s), y2.pb(y[N-1-i].s);
	F0R(q1,K+1) F0R(q2,K+1-q1) F0R(q3,K+1-q1-q2) ans = min(ans,query(q1,q2,q3,K-q1-q2-q3));
	cout << ans;
}