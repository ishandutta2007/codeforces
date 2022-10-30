#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string a,b;
int d = 0,q=0;

double choose(int w, int a) {
	if(a > w || a < 0) return 0;
	double ans = 1;
	for(int i = 1; i <= w; ++i) {
		ans *= double(i)/2;
	}
	for(int i = 1; i <= a; ++i)
		ans /= double(i);
	for(int i = 1; i <= w-a; ++i)
		ans /= double(i);
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	int n = a.size();
	for(int i = 0; i < n; ++i) {
		if(a[i] == '+') ++d;
		else --d;
	}
	for(int i = 0; i < n; ++i) {
		if(b[i] == '+') --d;
		else if(b[i] == '-') ++d;
		else ++q;
	}
	d = abs(d);
	if((q+d)%2!=0) {
		cout << "0\n";
		return 0;
	}
	int a = (q+d)/2;
	cout << setprecision(12) << fixed << choose(q,a) << "\n";
	return 0;
}