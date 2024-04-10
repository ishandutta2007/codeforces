//.s
#include<bits/stdc++.h>

using namespace std;

#define FAIL {cout << "no\n"; return 0;}

const int MAXN = 3e3 + 10;

int n, x[MAXN], sec[MAXN];
short match[MAXN][MAXN];

bool cmp(int u, int v){return x[u] > x[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;	cin >> n >> k;
	int sm = 0, tot = n*(n-1);
	for (int i = 0; i < k; i++)	cin >> x[i], sm += x[i];
	if (sm>tot || sm+(n-k)*x[k-1] < tot)	FAIL

	if (k^n){
		int rem = tot-sm, remp = n-k;
		int ls = rem/remp, mr = rem/remp+1, i;
		for (i = k; rem%remp && i < n; i++)
			x[i]=mr, remp--, rem-=mr;
		for (; i < n; i++)
			x[i] = ls;
	}

	{
		int _n = n;
		iota(sec, sec+n, 0);
		while (n){
			sort(sec, sec + n, cmp);
			int nd = x[sec[0]];
			if (nd < 0 || nd>(n-1<<1))	FAIL

			int i;
			for (i = n-1; i; i--)
				if (nd){
					if (nd>1){
						match[sec[0]][sec[i]] = 1;
						nd -= 2;
					}
					else{
						nd--;
						match[sec[0]][sec[i]] = match[sec[i]][sec[0]] = 2;
						x[sec[i]]--;
					}
				}
				else
					match[sec[i]][sec[0]] = 1, x[sec[i]] -= 2;

			rotate(sec, sec + 1, sec+n--);
		}
		n = _n;
	}

	{
		cout << "yes\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				if (i == j)	cout << "X";
				else if (match[i][j] == 0)	cout << "L";
				else if (match[i][j] == 1)	cout << "W";
				else cout << "D";
			cout << "\n";
		}
	}
	return 0;
}