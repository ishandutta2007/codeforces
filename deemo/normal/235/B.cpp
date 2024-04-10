//Never left without saying goodbye..

#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;

int n;
ld vec[MAXN], d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(9);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	d[0] = 0;
	ld sum = 0;
	for (int i = 0; i < n; i++){
		d[i + 1] = d[i] + vec[i];
		d[i + 1] += sum * vec[i] * 2.0;
		sum *= vec[i];
		sum += vec[i];
	}
	cout << d[n] << "\n";
	return 0;
}