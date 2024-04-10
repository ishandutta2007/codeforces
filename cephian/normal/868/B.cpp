#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 60*60*12;
bool filled[N];

int cnv(int h, int m, int s) {
	return (h%12)*60*60 + m*60 + s;
}

int main() {	
	int h,m,s,t1,t2;
	fio;
	cin >> h >> m >> s >> t1 >> t2;
	filled[m*60*12 + s] = filled[s*60*12] = filled[cnv(h,m,s)] = true;
	t1  = cnv(t1,0,0), t2 = cnv(t2,0,0);
	bool ok1=true, ok2 = true;
	for(int i = t1; i != t2; i=(i+1)%N) {
		if(i != t1 && filled[i]) ok1 = false;
		// cout << i << endl;
	}
	for(int i = t1; i != t2; i=(i-1+N)%N) {
		if(i != t1 && filled[i]) ok2 = false;
	}
	if(ok1 || ok2) cout << "YES\n";
	else cout << "NO\n";

}