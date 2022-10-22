#include<bits/stdc++.h>

using namespace std;

bool fit(int a, int b){return 0 <= a && a < 8 && 0 <= b && b < 8;}

int main(){
	string s;	cin >> s;
	int a = s[0] - 'a';
	int b = s[1] - '1';
	int ans = 0;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i || j)
				if (fit(a + i, b + j))	ans++;
	cout << ans << endl;
	return 0;
}