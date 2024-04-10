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

int n, m;
int a[11][11], b[11][11];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool was[11][111];

bool ok(){
	for (int j = 0; j < n * m; j++) for (int i = 0; i < n * m; i++) was[j][i] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		for (int s = 0; s < 4; s++){
			int nx = i + dx[s];
			int ny = j + dy[s];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m){
				was[a[i][j]][a[nx][ny]] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		for (int s = 0; s < 4; s++){
			int nx = i + dx[s];
			int ny = j + dy[s];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m){
				if (was[b[i][j]][b[nx][ny]]) return 0;
			}
		}
	}
	return 1;
}

vector<int> getFunc(int len){
	vector<int> ans;
	for (int i = len - 2; i >= 0; i -= 2) ans.pub(i);
	for (int i = len - 1; i >= 0; i -= 2) ans.pub(i);
	return ans;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;


	if (n * m < 10){
		int kk = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = kk++;

		vector<int> t;
		for (int i = 0; i < n * m; i++) t.pub(i);

		do{
			int dd = 0;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) b[i][j] = t[dd++];
			if (ok()){
				cout << "YES\n";
				for (int i = 0; i < n; i++){
					for (int j = 0; j < m; j++){
						cout << b[i][j] + 1 << ' ';
					}
					cout << "\n";
				}
				exit(0);
			};
		}while(next_permutation(all(t)));

		cout << "NO";
	} else {
		if (min(n, m) == 1){
			cout << "YES\n";
			if (n == 1){
				auto now = getFunc(m);
				for (int i = 0; i < m; i++) cout << now[i] + 1 << ' ';
			} else {
				auto now = getFunc(n);
				for (int i = 0; i < n; i++) cout << now[i] + 1 << '\n';
			}
			exit(0);
		}
		if (min(n, m) == 2){
			cout << "YES\n";
			if (n == 2){
				auto now = getFunc(m);
				for (int i = 0; i < m; i++) cout << now[i] + 1 << ' ';
				cout << endl;
				int cnt = m / 2;
				for (int i = 0; i < cnt; i++){
					int nxt = i + 1;
					if (i + 1 == cnt) nxt = 0;
					cout << now[nxt] + 1 + m << ' ';
				}
				for (int i = cnt; i < m; i++){
					int nxt = i - 1;
					if (i - 1 == cnt - 1) nxt = m - 1;
					cout << now[nxt] + 1 + m << ' ';
				}
			} else {
			    vector<vector<int> > gg;
	        	gg.resize(n);
	        	for (int i = 0; i < n; i++) gg[i].resize(m);
	        	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) gg[i][j] = i * m + j;
				auto now = getFunc(n);
				vector<int> ans1, ans2;
				for (int i = 0; i < n; i++) ans1.pub(gg[now[i]][0] + 1); //cout << now[i] + 1 << ' ';
				int cnt = n / 2;
				for (int i = 0; i < cnt; i++){
					int nxt = i + 1;
					if (i + 1 == cnt) nxt = 0;
					ans2.pub(gg[now[nxt]][1] + 1);
				}
				for (int i = cnt; i < n; i++){
					int nxt = i - 1;
					if (i - 1 == cnt - 1) nxt = n - 1;
					ans2.pub(gg[now[nxt]][1] + 1);
				}
				for (int i = 0; i < n; i++) cout << ans1[i] << ' ' << ans2[i] << "\n";
			}
			exit(0);
		}
		if (min(n, m) == 3){
			if (max(n, m) == 4){
				if (n == 3){
					cout << "YES\n";
					cout << "1 3 5 2\n";
					cout << "4 6 12 9\n";
					cout << "11 8 10 7\n";
					exit(0);
				} else {
					cout << "YES\n";
					cout << "1 3 4\n";
					cout << "5 7 2\n";
					cout << "11 6 8\n";
					cout << "9 10 12\n";
					exit(0);
				}
			} else {
				cout << "YES\n";
				if (n == 3){
					auto now = getFunc(m);
					for (int i = 0; i < m; i++) cout << now[i] + 1 << ' ';
					cout << endl;
					int cnt = m / 2;
					for (int i = 0; i < cnt; i++){
						int nxt = i + 1;
						if (i + 1 == cnt) nxt = 0;
						cout << now[nxt] + 1 + m << ' ';
					}
					for (int i = cnt; i < m; i++){
						int nxt = i - 1;
						if (i - 1 == cnt - 1) nxt = m - 1;
						cout << now[nxt] + 1 + m << ' ';
					}
					cout << endl;
					for (int i = 0; i < m; i++) cout << now[i] + 1 + 2 * m << ' ';
				} else {
    			    vector<vector<int> > gg;
    	        	gg.resize(n);
    	        	for (int i = 0; i < n; i++) gg[i].resize(m);
    	        	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) gg[i][j] = i * m + j;
    				auto now = getFunc(n);
    				vector<int> ans1, ans2;
    				for (int i = 0; i < n; i++) ans1.pub(gg[now[i]][0] + 1); //cout << now[i] + 1 << ' ';
    				int cnt = n / 2;
    				for (int i = 0; i < cnt; i++){
    					int nxt = i + 1;
    					if (i + 1 == cnt) nxt = 0;
    					ans2.pub(gg[now[nxt]][1] + 1);
    				}
    				for (int i = cnt; i < n; i++){
    					int nxt = i - 1;
    					if (i - 1 == cnt - 1) nxt = n - 1;
    					ans2.pub(gg[now[nxt]][1] + 1);
    				}
    				
					for (int i = 0; i < n; i++) cout << ans1[i] << ' ' << ans2[i] << ' ' << ans1[i] + 2 << "\n";
				}
			}
			exit(0);
		}
		auto now1 = getFunc(m);
		auto now2 = getFunc(n);

		vector<vector<int> > gg, dd;
		gg.resize(n); dd.resize(n);
		for (int i = 0; i < n; i++) gg[i].resize(m), dd[i].resize(m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dd[i][j] = i * m + j;

		for (int j = 0; j < m; j++){
			for (int i = 0; i < n; i++){
				gg[i][j] = dd[now2[i]][now1[j]];
			}
		}

		cout << "YES\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << gg[i][j] + 1 << ' ';
			}
			cout << "\n";
		}

	}
}