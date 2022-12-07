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

char s[1000100], t[1000100];
int n, m;
int cnt[10], cal[10], a[10];
char res1[2000100], res2[2000100], res3[2000100];

void check(){
	memset(res1, 0, sizeof(res1)); int l1 = 0;
	memset(res2, 0, sizeof(res2)); int l2 = 0;
	memset(res3, 0, sizeof(res3)); int l3 = 0;

	bool flag1 = 0, flag2 = 0;
	int b[10]; memcpy(b, a, sizeof(a));
	if (t[0] > '0'){
		memcpy(res1, t, sizeof(t)); l1 = m;
		for(int i = 0; i < 10; ++i)
			while(cnt[i] > cal[i] + a[i]){
				res1[l1++] = '0' + i;
				a[i]++;
			}
		flag1 = 1;
	}
	memcpy(a, b, sizeof(b));
	for(int i = 1; i < 10; ++i)
		if(cnt[i] > cal[i] + a[i]){
			res2[l2++] = res3[l3++] = '0' + i;
			a[i]++;
			flag2 = 1;
			break;
		}
	if(flag2){
		memcpy(b, a, sizeof(a));
		for(int i = 0; i < t[0] - '0'; ++i)
			while(cnt[i] > cal[i] + a[i]){
				res2[l2++] = '0' + i;
				a[i]++;
			}
		memcpy(res2 + l2, t, sizeof(t)); l2 += m;
		for(int i = t[0] - '0'; i < 10; ++i)
			while(cnt[i] > cal[i] + a[i]){
				res2[l2++] = '0' + i;
				a[i]++;
			}
		
		memcpy(a, b, sizeof(b));
		for(int i = 0; i <= t[0] - '0'; ++i)
			while(cnt[i] > cal[i] + a[i]){
				res3[l3++] = '0' + i;
				a[i]++;
			}
			memcpy(res3 + l3, t, sizeof(t)); l3 += m;
		for(int i = t[0] - '0' + 1; i < 10; ++i)
			while(cnt[i] > cal[i] + a[i]){
				res3[l3++] = '0' + i;
				a[i]++;
			}
		int out = 2;
		for(int i = 0; i < l2; ++i)
			if(res2[i] != res3[i]){
				out = res2[i] < res3[i] ? 2 : 3;
				break;
			}
		if(flag1){
			if(out == 2){
				for(int i = 0; i < l2; ++i)
					if(res2[i] != res1[i]){
						out = res2[i] < res1[i] ? 2 : 1;
						break;
					}
			}else{
				for(int i = 0; i < l2; ++i)
					if(res3[i] != res1[i]){
						out = res3[i] < res1[i] ? 3 : 1;
						break;
					}
			}
		}
		if(out == 1) cout << res1;
		else if(out == 2) cout << res2;
		else cout << res3;
	}else if(flag1) cout << res1; else return;
	exit(0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
#endif
	cin >> s;
	cin >> t;	
	n = strlen(s), m = strlen(t);

	if(n == 2){
		if(s[0] == '1') cout << s[1];
		else cout << s[0];
		return 0;
	}

	for(int i = 0; i < n; ++i) cnt[s[i] - '0']++;
	for(int i = 0; i < m; ++i) cal[t[i] - '0']++;
	for(int i = 1; i < n; ++i){
		if(n - i > 10) continue;
		memset(a, 0, sizeof(a));
		int t = i, tot = 0;
		while(t){
			a[t % 10]++;
			t /= 10;
			tot++;
		}
		bool flag = 1;
		for(int j = 0; j < 10; ++j)
			if(a[j] + cal[j] > cnt[j]){
				flag = 0;
				break;
			}
		if(n - tot == i)
			if(flag) check();
	}
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