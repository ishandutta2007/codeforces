#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define time kljasdfi

const int MAXN = 1e5 + 10;

int n;
ll ln[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ln[i], ln[i] <<= 1;
	cin >> s;

	ll time = 0, stamina = 0;
	ll undoW = 0, undoG = 0;
	bool markW = 0, markG = 0;

	for (int i = 0; i < n; i++)
		if (s[i] == 'W'){
			markW = 1;
			ll rem = ln[i];

			ll g = min(rem, stamina);
			time += g;
			stamina -= g;
			undoW += g;
			rem -= g;

			time += (rem>>1)*3 + (rem>>1);
			undoW += rem>>1;
		}
		else if (s[i] == 'G'){
			markG = 1;
			ll rem = ln[i];

			ll g = min(rem, stamina);
			time += g;
			stamina -= g;
			undoG += g;
			rem -= g;

			g = min(rem>>1, undoW);
			undoW -= g;
			time += g * 2;
			stamina += g*2;

			g = min(rem, stamina);
			time += g;
			stamina -= g;
			rem -= g;
			undoG += g;

			time += (rem>>1)*5 + (rem>>1);
			undoG += rem>>1;
		}
		else{
			ll rem = ln[i];
			
			ll g = min(rem, stamina);
			time += g;
			stamina -= g;
			rem -= g;

			g = min(rem>>1, undoW);
			undoW -= g;
			time += g * 2;
			stamina += g*2;

			g = min(rem, stamina);
			time += g;
			stamina -= g;
			rem -= g;

			g = min(rem>>1, undoG);
			undoG -= g;
			time += g*4;
			stamina += g*2;

			g = min(rem, stamina);
			time += g;
			stamina -= g;
			rem -= g;

			g = rem>>1;
			if (markW)
				time += g * 6;
			else
				time += g*10;
			stamina += g*2;

			g = min(rem, stamina);
			time += g;
			stamina -= g;
			rem -= g;
		}

	assert(stamina == 0);
	cout << time/2 << "\n";
	return 0;
}