#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;

typedef long long ll;

template <typename T> inline bool cmin(T & a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool cmax(T & a, const T &b) { return a < b ? a = b, 1 : 0; }

int n, s[233]; 
int main(){
	int i;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> s[i];
	int a, b; a = b = 0;
	for(i = 1; i <= n; i++) 
		if(s[i]) 
			a = max(a, b) + 1;
		else 
			b++;
	cout << max(a, b);
	return 0;
}