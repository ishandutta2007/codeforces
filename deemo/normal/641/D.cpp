#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<iomanip>
#include<cassert>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 1e5 + 10;

int n;
ld mn[MAXN], mx[MAXN], p1[MAXN], p2[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(9);
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> mx[i];
	for (int i = 1; i <= n; i++)	cin >> mn[i];
	for (int i = 1; i <= n; i++){
		ld mul = mx[i] + p1[i - 1] * p2[i - 1];
		ld sum = mn[i] + p1[i - 1] + p2[i - 1] - p1[i - 1] * p2[i - 1] + mul;
		ld del = sum * sum - 4. * mul;
		ld sq = (del>=0?sqrt(del):0);
		p1[i] = (sum + sq)/ 2.;
		p2[i] = sum - p1[i];
		if (p1[i] > p2[i])	swap(p1[i], p2[i]);
	}
	
	for (int i = 1; i <= n; i++)	cout << p1[i] - p1[i - 1] << " ";
	cout << "\n";
	for (int i = 1; i <= n; i++)	cout << p2[i] - p2[i - 1] << " ";
	cout << "\n";
	return 0;
}