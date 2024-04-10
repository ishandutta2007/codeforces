#include<iostream>

using namespace std;

const int MAXN = 1e5 + 30;

int n, s, t;
int p[MAXN];

int main(){
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int i;
	for (i = 0; i < n; i++){
		if (s == t)	break;
		s = p[s];
	}
	if (s == t)	cout << i << endl;
	else	cout << -1 << endl;
	return 0;
}