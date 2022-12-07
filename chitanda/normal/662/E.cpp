//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))

const int maxn = 5010;
int n, ans;
int tim[maxn][3], canHack[3], solved[3], maxScore[3], willHack[3];
int f[2][91][91][91];

int getScore(int i, int j){
	if(!tim[i][j]) return 0;
	return maxScore[j] * (250 - abs(tim[i][j])) / 250;
}

int calc(int i){
	return getScore(i, 0) + getScore(i, 1) + getScore(i, 2);
}

bool cantoHack(int i){
	return tim[i][0] < 0 || tim[i][1] < 0 || tim[i][2] < 0;
}

int solve(){
	int myScore = 0;
	for(int i = 0; i < 3; ++i) myScore += willHack[i] * 100 + getScore(1, i);
	
	memset(f, 0, sizeof(f));
	bool tag = 0;

	for(int i = 2; i <= n; ++i){
		if(calc(i) <= myScore) continue;
		if(!cantoHack(i)) continue;
		tag ^= 1;
		for(int j = 0; j <= willHack[0]; ++j)
			for(int k = 0; k <= willHack[1]; ++k)
				for(int l = 0; l <= willHack[2]; ++l)
					f[tag][j][k][l] = f[tag ^ 1][j][k][l];

		for(int j = 0; j < 2; ++j){
			if(j && tim[i][0] >= 0) continue;
			for(int k = 0; k < 2; ++k){
				if(k && tim[i][1] >= 0) continue;
				for(int l = 0; l < 2; ++l){
					if(l && tim[i][2] >= 0) continue;
					int hisScore = (!j) * getScore(i, 0) + (!k) * getScore(i, 1) + (!l) * getScore(i, 2);
					if(hisScore > myScore) continue;
					for(int t0 = j; t0 <= willHack[0]; t0++)
						for(int t1 = k; t1 <= willHack[1]; t1++)
							for(int t2 = l; t2 <= willHack[2]; t2++)
								f[tag][t0][t1][t2] = max(f[tag][t0][t1][t2], f[tag ^ 1][t0 - j][t1 - k][t2 - l] + 1);
				}
			}
		}
	}
	int res = 1 - f[tag][willHack[0]][willHack[1]][willHack[2]];
	for(int i = 1; i <= n; ++i) if(calc(i) > myScore) res++;
	return res;
}

void foreach(int p){
	if(p == 3){
		ans = min(ans, solve());
		return;
	}
	
	for(int i = 0; i < 6; ++i){
		int l = i == 5 ? 0 : (n >> (i + 1)) + 1;
		int r = n >> i;
		
		if(solved[p] >= l && solved[p] - canHack[p] <= r){
			maxScore[p] = (i + 1) * 500;
			willHack[p] = min(canHack[p], solved[p] - l);
			foreach(p + 1);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 3; ++j){
			scanf("%d", tim[i] + j);
			if(tim[i][j] != 0){
				solved[j]++;
				if(tim[i][j] < 0) canHack[j]++;
			}
		}
	}
	if(canHack[0] + canHack[1] + canHack[2] >= 89){
		printf("%d\n", 1);
		return 0;
	}
	ans = n;
	foreach(0);
	printf("%d\n", ans);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/