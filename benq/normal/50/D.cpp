#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define mp make_pair
#define f first
#define s second

int n,k,e;
pii ori;
vector<pii> ob;
vector<double> prob;

double calc() { // probability of failing
	vector<double> num(n+1);
	num[0] = 1;
	F0R(i,n) {
		vector<double> num1(n+1);
		F0R(j,i+1) {
			num1[j+1] += num[j]*prob[i];
			num1[j] += num[j]*(1-prob[i]);
		}
		num = num1;
	}
	double ans = 0;
	F0R(i,k) ans += num[i];
	return ans;
}

double dist(pii a, pii b) {
	b.f -= a.f, b.s -= a.s;
	return b.f*b.f+b.s*b.s;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> e; 
	ob.resize(n); prob.resize(n);
	cin >> ori.f >> ori.s;
	
	F0R(i,n) cin >> ob[i].f >> ob[i].s;
	double low = 0, high = 16000000;
	while (high-low>0.00000001) {
		double mid = (low+high)/2;
		F0R(i,n) {
			if (dist(ori,ob[i]) <= mid) prob[i] = 1;
			else prob[i] = exp(1-dist(ori,ob[i])/mid);
		}
		if (1000*calc() >= e) low = mid;
		else high = mid;
	}
	cout << fixed << setprecision(9) << sqrt(low) << "\n";
}