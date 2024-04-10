#include <iostream>

using namespace std;

int n,c;
int p[1005],t[1005];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> c;
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	for(int i = 0; i < n; ++i)
		cin >> t[i];
	int a=0,b=0;
	int s1 = 0,s2 = 0;
	for(int i = 0; i < n; ++i) {
		s1 += t[i];
		s2 += t[n-1-i];
		a += max(0, p[i]-s1*c);
		b += max(0, p[n-i-1]-s2*c);
	}
	if(a > b) cout << "Limak\n";
	else if(a < b) cout << "Radewoosh\n";
	else cout << "Tie\n";
	return 0;
}