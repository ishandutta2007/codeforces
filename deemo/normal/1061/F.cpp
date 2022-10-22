#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 15e2 + 10;

int n, k, sec[MAXN], u, v;

bool yes(){
	string s; cin >> s;
	return s[0] == 'Y';
}

bool cmp(int a, int b){
	cout << "? " << u+1 << " " << a+1 << " " << b+1 << endl;
	return yes();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin >> n >> k;
	int t = 1, h = 0, leaves = 1;
	while (t < n){
		leaves *= k;
		t += leaves;
		h++;
	}

	while (true){
		u = rand()%n, v = rand()%n;
		if (u == v) continue;
		
		int sz = 0;
		sec[sz++] = u, sec[sz++] = v;
		for (int i = 0; i < n; i++)
			if (i^u && i^v){
				cout << "? " << u+1 << " " << i+1 << " " << v+1 << endl;
				if (yes())
					sec[sz++] = i;
			}

		if (sz != 1 + 2*h) continue;
		sort(sec, sec + sz, cmp);
		cout << "! " << sec[sz/2]+1 << endl;
		return 0;
	}
	return 0;
}