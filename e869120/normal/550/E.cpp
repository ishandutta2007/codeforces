#include<iostream>
#include<string>
using namespace std;
int n, a[100009], L = -1; string S = "";
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i]; if (a[i] == 1)L = i; }
	if (a[n - 1] == 1 || (n == 2 && a[0] == 0 && a[1] == 0)) { cout << "NO" << endl; return 0; }
	if (n >= 3 && a[n - 3] == 1 && a[n - 2] == 0 && a[n - 1] == 0) {
		int P = -1;
		for (int i = 0; i <= L; i++) { if (a[i] == 0) { P = i; break; } }
		if (P == -1) { cout << "NO" << endl; return 0; }
		S += "(";
		if (P >= 1) {
			S += "(";
			for (int i = 0; i < P; i++) { if (i >= 1)S += "->"; S += "1"; }S += ")->";
		}
		S += "(0->(";
		for (int j = P + 1; j <= L + 1; j++) { if (j >= P + 2)S += "->"; S += to_string(a[j]); }
		S += ")))->0";
	}
	else {
		if (L >= 0) {
			S += "(";
			if (L >= 1) {
				S += "(";
				for (int i = 0; i < L; i++) { if (i >= 1)S += "->"; S += to_string(a[i]); }
				S += ")->";
			}
			S += to_string(a[L]);
			S += ")->";
		}
		S += "(";
		for (int i = L + 1; i < n - 1; i++) { if (i >= L + 2)S += "->"; S += "("; S += to_string(a[i]); }
		for (int i = L + 1; i < n - 1; i++)S += ")"; if (L + 1 < n - 1)S += "->"; S += to_string(a[n - 1]); S += ")";
	}
	cout << "YES" << endl;
	cout << S << endl;
	return 0;
}