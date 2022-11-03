#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
vector<int> a, b;

bool can(int tt){
	int uk = 0;
	for (int i = 0; i < b.size(); i++){
		if (uk == (int)a.size()) break;
		if (a[uk] < b[i]){
			if (b[i] - a[uk] > tt) return 0;
			int len = b[i] - a[uk];
			while(uk < a.size() && a[uk] <= b[i]) uk++;
			while(uk < a.size()){
				int len2 = a[uk] - b[i];
				if (min(len, len2) * 2 + max(len, len2) <= tt) uk++;
				else break;
			}
		} else {
			int last = b[i];
			int ost = tt;
			while(uk < a.size() && a[uk] - last <= ost){
				ost -= a[uk] - last;
				last = a[uk];
				uk++;
			}
		}
	}
	if (uk != (int)a.size()) return 0;
	return 1;
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '*'){
			a.pub(i);
		} else if (s[i] == 'P'){
			b.pub(i);
		}
	}

	int vl = -1, vr = 2 * (int)s.size() + 1;
	while(vl + 1 < vr){
		int vm = (vl + vr) >> 1;
		if (can(vm))
			vr = vm;
		else
			vl = vm;
	}
	cout << vr;
}