#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, k;

bool ask(int a, int b){
	cout << 1 << ' ' << a << ' ' << b << endl;
	string s;
	cin >> s;
	return s == "TAK";
}

int solve(int l, int r){
	int vl = l - 1, vr = r;
	while(vl + 1 < vr){
		int vm = (vl + vr) >> 1;
		if (ask(vm, vm + 1))
			vr = vm;
		else
			vl = vm;
	}
	return vr;
}

int solve2(int l, int r){
	int vl = l - 1, vr = r;
	while(vl + 1 < vr){
		int vm = (vl + vr) >> 1;
		if (ask(vm + 1, vm))
			vl = vm;
		else
			vr = vm;
	}
	return vr;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	int fr = solve(1, n);
//	cout << "===" << fr << endl;
	if (fr == 1){
		cout << 2 << ' ' << fr << ' ' << solve2(2, n) << endl;
	} else {
		int sc = solve(1, fr - 1);
		if (ask(sc, fr)){
			cout << 2 << ' ' << fr << ' ' << sc << endl;
		} else {
			cout << 2 << ' ' << fr << ' ' << solve2(fr + 1, n) << endl;
		}
	}
}