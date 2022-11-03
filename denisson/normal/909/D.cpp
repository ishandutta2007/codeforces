#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

string s;
int ans = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	vector<pair<int, int> > t;
	for (int i = 0; i < s.size(); i++){
		if (t.size() == 0 || t.back().x != s[i] - 'a'){
			t.pub(mp(s[i] - 'a', 1));
		} else t.back().y++;
	}
	while(1){
		if (t.size() <= 1) break;
		int it = 1e9;
		for (int i = 0; i < t.size(); i++){
			if (i == 0 || i + 1 == t.size()){
				it = min(it, t[i].y);
			} else {
				it = min(it, (t[i].y + 1) / 2);
			}
		}
		ans += it;
		vector<pair<int, int> > now;
		for (int i = 0; i < t.size(); i++){
			int ost = t[i].y;
			if (i == 0 || i + 1 == t.size()){
				ost -= it;
			} else {
				ost -= it * 2;
			}
			if (ost > 0){
				if (now.size() == 0 || now.back().x != t[i].x){
					now.pub(mp(t[i].x, ost));
				} else now.back().y += ost;
			}
		}
		t = now;
	}
	cout << ans;
}