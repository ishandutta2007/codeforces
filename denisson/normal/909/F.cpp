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

int n;

bool step(int x){
	int val = 0;
	while((1 << val) < x) val++;
	return (x == (1 << val));
}

int was[1111];
int tt[1111];
void gen(int v){
	if (v == 26 + 1){
		for (int i = 1; i <= 26; i++) cout << tt[i] << ' ';
		cout << endl;
	} else {
		if (v == 1){
			was[14] = 1;
			tt[v] = 14;
			gen(v + 1);
			exit(0);
		}
		if (v == 2){
			was[13] = 1;
			tt[v] = 13;
			gen(v + 1);
			exit(0);
		}
		for (int i = 1; i <= 26; i++) if (was[i] == 0){
			if ((v & i) != 0) continue;
			if (v == i) continue;
			was[i] = 1;
			tt[v] = i;
			gen(v + 1);
			was[i] = 0;
		}
	}
}

vector<int> ans;
void go(int len){
	if (len == 0) return;
	if (len == 2){
		ans.pub(2);
		ans.pub(1);
		return;
	}
	if (len == 4){
		ans.pub(2);
		ans.pub(1);
		ans.pub(4);
		ans.pub(3);
		return;
	}

	int it = 1;
	int last = 6;
	int ost = -2;
	for (int i = 8; i <= len; i += 2){
		ost += 2;
		if (ost == last){
			ost = -2;
			last = i;
		}
	}
	if (ost == -2) ost = 0;
	int save = last;
	for (int i = 0; ; i++){
		ans.pub(last);
		last--;
		if (last == ost) break;
	}
	for (int i = len; i > save; i--){ 
		//cout << i << ' ';
		ans.pub(i);
	}

	go(ost);
}

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	//for (n = 6; n < 100000; n++){
	if (1){
		if (n % 2 == 1){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			ans.clear();
			go(n);
			int it = 1;
			for (int x : ans){
				if ((x & it) != 0 || x == it) cout << n << endl, assert(0);
				it++;
				cout << x << ' ';
			}
			//if (n == 220) exit(0);		
			cout << "\n";
			//exit(0);
		}
	}
	//continue;

	if (1){
		if (n < 6 || step(n)){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			vector<int> t = {3, 6, 1, 5, 4, 2};
			if (n == 6){
				for (int x : t) cout << x << ' ';
				exit(0);
			}
			t = {3, 6, 1, 5, 4, 7, 2};
			for (int i = 8; i <= n;){
				if (i + 1 <= n){
					t.pub(i + 1);
					t.pub(i);
					i += 2;
				} else {
					int x = t.back();
					t.pop_back();
					t.pub(i);
					t.pub(x);
					break;
				}
			}
			int it = 1;
			for (int x : t){
				if ((x & it) == 0) assert(0);
				it++;
				cout << x << ' ';
			}
		}
	}
	//}
	exit(0);

	gen(1);
	exit(0);

	vector<int> t;
	for (int i = 0; i < n; i++) t.pub(i + 1);
	do{
		bool f = 1;
		for (int i = 0; i < t.size(); i++){
			if (t[i] == i + 1){
				f = 0;
				break;
			}
			if ((t[i] & (i + 1)) != 0){
				f = 0;
				break;
			}
		}
		if (f){
			for (int i = 0; i < t.size(); i++) cout << t[i] << ' ';
			cout << endl;
		}

	}while(next_permutation(all(t)));
}