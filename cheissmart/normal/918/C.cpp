#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0, n = s.size();
	for (int l=0;l<n;l++) { 
		int tl = 0, tr = 1;
		for (int r=l;r<n;r++) {
			if (s[r] == '(') 
				tl++, tr++;
			else if (s[r] == ')') 
				tl--, tr--, tl = max(0, tl);
			else 
				tr++, tl--, tl = max(0, tl);
				
			if (tl == tr) break;
			if ((r-l+1) % 2 == 0 && tl == 0) 
				ans++;
		}
	}
	cout << ans << endl;
}