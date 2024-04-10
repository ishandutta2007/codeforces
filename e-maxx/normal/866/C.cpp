#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 51;
const int MAXT = MAXN * 100;


int n, twanted, t1[MAXN], t2[MAXN], prob[MAXN];


bool read() {
	if (!(cin >> n >> twanted))
		return false;
	forn(i, n)
		cin >> t1[i] >> t2[i] >> prob[i];
	return true;
}


pair<double,double> coeff[MAXN][MAXT];
double d[MAXN][MAXT];

void solve() {
//    ford(i, n + 1) {
//        ford(t, twanted + 1) {
//            if (i == n) {
//                coeff[i][t] = mp(0, 0);
//                continue;
//            }
//            double p = prob[i] * 0.01;
//            pair<double,double> nd1 = t + t1[i] <= twanted ? coeff[i + 1][t + t1[i]] : pair<double,double>(1, 0);
//            nd1.sc += t1[i];
//            nd1.fs *= p;
//            nd1.sc *= p;
//            pair<double,double> nd2 = t + t2[i] <= twanted ? coeff[i + 1][t + t2[i]] : pair<double,double>(1, 0);
//            nd2.sc += t2[i];
//            nd2.fs *= 1 - p;
//            nd2.sc *= 1 - p;
//            coeff[i][t] = mp(nd1.fs + nd2.fs, nd1.sc + nd2.sc);
//        }
//    }
//
//    d[0][0] = coeff[0][0].sc / (1 - coeff[0][0].fs);
//    cerr << coeff[0][0].fs << ' ' << coeff[0][0].sc << ' ' << d[0][0] << endl;

    double lt = 0, rt = 1E8;
    forn(iter, 100) {
        double mid = (lt + rt) / 2;
        forn(i, n+1)
            forn(t, twanted+1)
                d[i][t] = mid;

        ford(i, n + 1) {
            ford(t, twanted + 1) {
                double &my = d[i][t];
                if (i == n) {
                    my = 0;
                    continue;
                }

                double p = prob[i] * 0.01;
                double nd =
                        p * (t1[i] + (t + t1[i] <= twanted ? d[i + 1][t + t1[i]] : mid))
                        + (1 - p) * (t2[i] + (t + t2[i] <= twanted ? d[i + 1][t + t2[i]] : mid));
                my = min(mid, nd);
            }
        }

        if (d[0][0] < mid)
            rt = mid;
        else
            lt = mid;
    }

	cout << (rt + lt) / 2 << endl;
}


int main() {
#ifdef EMAXX_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

    cout.precision(20);
    cout.setf(ios::fixed);
    cerr.precision(20);
    cerr.setf(ios::fixed);

    int tt = 0;
	while (read()) {
		cerr << "Case " << ++tt << ": starting..." << endl;
		solve();
	}
    cerr << "Finished.";

	return 0;
}