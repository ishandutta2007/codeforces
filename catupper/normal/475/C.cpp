#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

char field[1080][1080];
int n, m;
int si = 1 << 30, sj = 1 << 30;
int dp[1080][1080];
bool come[1080][1080];
int cnt;
int xs[] = {0, 1, 0, -1}, ys[] = {1, 0, -1, 0};
int area(int x, int y, int nlen, int mlen){
	x--,y--;
	return dp[x + nlen][y + mlen] + dp[x][y]
	      -dp[x + nlen][y] - dp[x][y + mlen];
}

bool able(int nlen, int mlen){
	int nowi = si, nowj = sj;
	if(area(nowi, nowj, nlen, mlen) != nlen * mlen)return false;
	int are = nlen * mlen;
	while(true){		
		int mi = area(nowi + 1, nowj, nlen, mlen);
		int mj = area(nowi, nowj + 1, nlen, mlen);
		if(mj == nlen * mlen){
			nowj++;
			are += nlen;
		}
		else if(mi == nlen * mlen){
			nowi++;
			are += mlen;
		}
		else{
			return cnt == are;
		}
	}
}

int dfs(int x, int y){
	if(come[x][y])return 0;
	come[x][y] = true;
	int res = 0;
	if(field[x][y] == 'X')res++;
	else return 0;
	for(int i = 0;i < 4;i++){
		int tx = x + xs[i], ty = y + ys[i];
		res += dfs(tx, ty);
	}
	return res;
}

int main(){
	scanf("%d%d", &n, &m);
	int ncome, naway, mcome, maway;
	ncome = naway = mcome = maway = 1 << 30;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf(" %c", &field[i][j]);
			if(field[i][j] == 'X'){
				si = min(si, i);
				sj = min(sj, j);
				dp[i][j] = 1;
				cnt++;
				if(i == n)naway = min(naway, n + 1);
				if(j == m)maway = min(maway, m + 1);
			}
			if(field[i][j] == 'X' && field[i - 1][j] != 'X'){
				ncome = min(ncome, i);
			}
			if(field[i][j] != 'X' && field[i - 1][j] == 'X'){
				naway = min(naway, i);
			}
			if(field[i][j] == 'X' && field[i][j - 1] != 'X'){
				mcome = min(mcome, j);
			}
			if(field[i][j] != 'X' && field[i][j - 1] == 'X'){
				maway = min(maway, j);
			}
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	if(dfs(si, sj) != cnt){
		cout << -1 << endl;
		return 0;
	}
	int nlen = naway - ncome;
	int mlen = maway - mcome;
	int res = 1 << 30;
		for(int i = 1;i + sj < 1005;i++){
			if(able(nlen, i)){
				res = min(res, nlen * i);
break;
			}
		}
		for(int i = 1;i + si < 1005;i++){
			if(able(i, mlen)){
				res = min(res, mlen * i);break;
			}
		}
		if(res == 1 << 30)res = -1;
		cout << res << endl;
	return 0;
}