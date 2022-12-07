#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 987654321
#define PI 3.14159265358979323
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<double, string> P;
int main() {
	double h, m, s, t1, t2;
	scanf("%lf%lf%lf%lf%lf", &h, &m, &s, &t1, &t2);
	vector<P> v;
	v.push_back(P(h * 30 + m*0.5 + s / 120, "H"));
	v.push_back(P(m*6 + s *0.1, "M"));
	v.push_back(P(s*6, "S"));
	v.push_back(P(30 * t1, "T1"));
	v.push_back(P(30 * t2, "T2"));
	sort(v.begin(), v.end());
	for (int i = 0; i < 5; i++)
	{
		int j = (i + 1) % 5;
		if (v[i].second == "T1"&&v[j].second == "T2" || v[i].second == "T2"&&v[j].second == "T1")
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}