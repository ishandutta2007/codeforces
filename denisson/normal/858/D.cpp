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
string a[70007];
unordered_map<int, int> was[10];
int step[9];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	step[0] = 1;
	for (int i = 1; i < 9; i++) step[i] = step[i - 1] * 10;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		for (int j = 0; j < a[i].size(); j++){
			int now = 0;
			for (int s = j; s < a[i].size(); s++){
				now = now * 10 + a[i][s] - '0';
				was[s - j + 1][now]++;
			}
		}
	}
	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < a[i].size(); j++){
			int now = 0;
			for (int s = j; s < a[i].size(); s++){
				now = now * 10 + a[i][s] - '0';
				was[s - j + 1][now]--;
			}
		}

		bool st = 0;
		for (int len = 1; len <= a[i].size(); len++){
			if (st) break;
			int now = 0;
			for (int j = 0; j < len; j++) now = now * 10 + a[i][j] - '0';
			if (was[len][now] == 0){
				for (int j = 0; j < len; j++) cout << a[i][j];
				cout << "\n";
				st = 1;
			}
			for (int j = len; j < a[i].size(); j++){
				if (st) break;
				int v = j - len;
				now -= (a[i][v] - '0') * step[len - 1];
				now *= 10;
				now += a[i][j] - '0';
				if (was[len][now] == 0){
					for (int s = 0; s < len; s++) cout << a[i][v + s + 1];
					cout << "\n";
					st = 1;
				}
			}
		}

		for (int j = 0; j < a[i].size(); j++){
			int now = 0;
			for (int s = j; s < a[i].size(); s++){
				now = now * 10 + a[i][s] - '0';
				was[s - j + 1][now]++;
			}
		}
	}
}