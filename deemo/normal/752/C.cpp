#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n;){
		int j = i;
		int cl = 0, cr = 0, cu = 0, cd = 0;
		while (j < n){
			if (s[j] == 'L')	cl++;
			if (s[j] == 'R')	cr++;
			if (s[j] == 'D')	cd++;
			if (s[j] == 'U')	cu++;
			if (cl && cr || cd && cu)	break;
			j++;
		}
		
		i = j;
		ans++;
	}
	cout << ans << endl;
	return 0;
}