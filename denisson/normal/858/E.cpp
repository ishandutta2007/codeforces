#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
set<int> s2, t2;
pair<string, int> a[100007];

bool isDig(char c){
	return c >= '0' && c <= '9';
}

int convert(string s){
	if (s[0] == '0') return -1;
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		if (!isDig(s[i])) return -1;
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

string con(int x){
	string ans;
	while(x){
		ans += '0' + x % 10;
		x /= 10;
	}
	reverse(all(ans));
	return ans;
}

vector<pair<string, string> > ans;

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int k1 = 0, k2 = 0;
	set<string> gg;
	for (int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
		gg.insert(a[i].x);
		if (a[i].y == 1) k1++;
		else k2++;
	}
	for (int i = 1; i <= k1; i++) s2.insert(i);
	for (int i = k1 + 1; i <= k1 + k2; i++) t2.insert(i);
	
	vector<pair<string, int> > d1, d2, w1, w2;

	for (int i = 0; i < n; i++){
		int x = convert(a[i].x);
		if (a[i].y == 1){
			if (x >= 1 && x <= k1){
				//s1.erase(x);
				s2.erase(x);
			} else if (x >= k1 + 1 && x <= k1 + k2){
				t2.erase(x);
				d2.pub(a[i]);
			} else d1.pub(a[i]);
		} else {
			if (x >= 1 && x <= k1){
				s2.erase(x);
				w2.pub(a[i]);
			} else if (x >= k1 + 1 && x <= k1 + k2){
				//t1.erase(x);
				t2.erase(x);
			} else w1.pub(a[i]);
		}
	}

	string tmp;
	while(1){
		string hi;
		for (int i = 0; i < 6; i++) hi += (char)(rand() % 26 + 'a');
		if (gg.find(hi) == gg.end()){
			tmp = hi;
			break;
		}
	}

	/*for (auto c : w2){
		cout << c.x << ' ' << c.y << endl;
	}
	cout << endl;
	for (auto c : d2){
		cout << c.x << ' ' << c.y << endl;
	}
	cout << endl;
	//exit(0);

	for (int x : s2) cout << x << ' ';
		cout << endl;
	for (int x : t2) cout << x << ' ';
		exit(0);*/

	while(1){
		if (s2.size() > 0){
			if (d2.size()){
				ans.pub(mp(d2.back().x, con(*s2.begin())));
				t2.insert(convert(d2.back().x));
				//s1.erase(*s2.begin());
				s2.erase(s2.begin());
				d2.pop_back();
			} else {
				ans.pub(mp(d1.back().x, con(*s2.begin())));
				//s1.erase(*s2.begin());
				s2.erase(s2.begin());
				d1.pop_back();
			}
		} else if (t2.size() > 0){
			if (w2.size()){
				ans.pub(mp(w2.back().x, con(*t2.begin())));
				s2.insert(convert(w2.back().x));
				//t1.erase(*t1.begin());
				t2.erase(t2.begin());
				w2.pop_back();
			} else {
				ans.pub(mp(w1.back().x, con(*t2.begin())));
				//t1.erase(*t1.begin());
				t2.erase(t2.begin());
				w1.pop_back();
			}
		} else {
			if (d2.size() == 0) break;
			ans.pub(mp(d2[0].x, tmp));
			for (int i = 0; i < w2.size(); i++){
				ans.pub(mp(w2[i].x, d2[i].x));
				if (i + 1 < w2.size()) ans.pub(mp(d2[i + 1].x, w2[i].x));
				else {
					ans.pub(mp(tmp, w2[i].x));
				}
			}
			break;
		}
	}

	cout << ans.size() << "\n";
	for (auto c : ans){
		cout << "move " << c.x << ' ' << c.y << "\n";
	}
}