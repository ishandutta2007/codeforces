//int!
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;

char s[35];
int cnt[35];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%s", s + 1);
	for(int i = 1; i <= 26; ++i)
		if(s[i] == s[i + 1]){
			printf("Impossible\n");
			return 0;
		}
	for(int i = 1; i <= 27; ++i){
		cnt[s[i] - 'A']++;
	}
	int t1 = 0, t2 = 0, i = 1;
	for(;;++i)
		if(cnt[s[i] - 'A'] == 2){
			t1 = i; break;
		}
	++i;
	for(;;++i)
		if(cnt[s[i] - 'A'] == 2){
			t2 = i; break;
		}

	if(t1 > 28 - t2){
		reverse(s + 1, s + 28);
		t1 = 28 - t1;
		t2 = 28 - t2;
		swap(t1, t2);
	}

	int mid = (t1 + t2 - 1) / 2;
	for(int i = mid; i >= t1; --i) printf("%c", s[i]);
	for(int i = t2 + 1; i - t2 + (mid - t1 + 1) <= 13; ++i) printf("%c", s[i]);
	printf("\n");
	for(int i = mid + 1; i < t2; ++i) printf("%c", s[i]);
	for(int i = t1 - 1; i >= 1; --i) printf("%c", s[i]);
	int j = 13 + t2 - mid + t1 - 1;
	for(int i = 27; i > j; --i) printf("%c", s[i]);
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