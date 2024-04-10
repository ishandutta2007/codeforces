#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, t;
	string s;
	cin >> n >> t >> s;
	while(t--)
		for(int i = 0; i < n - 1; i++)
			if(s[i] == 'B' && s[i + 1] == 'G'){
				swap(s[i], s[i + 1]);
				i++;
				cerr << s << endl;
			}
	cout << s;
}