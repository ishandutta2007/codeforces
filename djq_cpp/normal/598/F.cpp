#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

PII operator+(const PII& A, const PII& B)
{
	return MP(A.first + B.first, A.second + B.second);
}
PII operator-(const PII& A, const PII& B)
{
	return MP(A.first - B.first, A.second - B.second);
}
LL operator*(const PII& A, const PII& B)
{
	return 1LL * A.first * B.first + 1LL * A.second * B.second; 
}
LL operator/(const PII& A, const PII& B)
{
	return -(1LL * A.first * B.second - 1LL * A.second * B.first);
}

int n, m;
PII ver[1005];
PII A, B; 

void init()
{
	return;
	int mn = 0;
	rep(i, n) if(ver[i] < ver[mn]) mn = i;
	rotate(ver, ver + mn, ver + n);
	
	rep1(i, n - 1) if((ver[(i + 1) % n] - ver[i]) / (ver[i] - ver[i - 1]) == 0) ver[i] = ver[i - 1];
	n = unique(ver, ver + n) - ver;
}

LL tar[1005];
vector<long double> ps;
vector<pair<long double, long double> > is;
double solve()
{
	B = B - A;
	rep(i, n) tar[i] = (ver[i] - A) / B;
	
	ps.clear(); is.clear();
	rep(i, n) {
		LL t0 = tar[i], t1 = tar[(i + 1) % n];
		PII v0 = ver[i], v1 = ver[(i + 1) % n];
		if(t0 == 0 && t1 == 0) is.push_back(MP((v0 - A) * B * (long double)1, (v1 - A) * B * (long double)1));
		else if((t0 >= 0 && t1 < 0) || (t0 < 0 && t1 >= 0))
		ps.push_back(((v0 - A) * B * (long double)t1 - (v1 - A) * B * (long double)t0) / (t1 - t0));
	}
	
	rep(i, is.size()) if(is[i].first > is[i].second) swap(is[i].first, is[i].second);
	sort(ps.begin(), ps.end());
	for(int i = 0; i < (int)ps.size(); i += 2) is.push_back(MP(ps[i], ps[i + 1]));
	sort(is.begin(), is.end());
	rep(i, is.size()) if(i != 0) is[i].second = max(is[i].second, is[i - 1].second);
	
	long double ans = 0;
	rep(i, is.size()) ans += i == 0 || is[i].first > is[i - 1].second ? is[i].second - is[i].first : is[i].second - is[i - 1].second;
	
	return ans / sqrt(B * B);
}

void getp(PII& A)
{
	double x, y;
	scanf("%lf%lf", &x, &y);
	x *= 100; y *= 100;
	x += x > 0 ? 0.5 : -0.5; y += y > 0 ? 0.5 : -0.5;
	A = MP(x, y);
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) getp(ver[i]);
	init();
	rep(i, m) {
		getp(A); getp(B);
		printf("%.10lf\n", solve() / 100);
	}
	return 0;
}