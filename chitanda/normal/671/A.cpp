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

int x[100100], y[100100];
int n;
double ta[100100], tb[100100];

double dis(int a, int b){
	return sqrt((ll)(x[a] - x[b]) * (x[a] - x[b]) + (ll)(y[a] - y[b]) * (y[a] - y[b]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	for(int i = 0; i < 3; i++) scanf("%d%d", x + i, y + i);
	cin >> n;
	int mina = 3, minb = 3;
	double sum = 0;
	for(int i = 3; i < n + 3; i++){
		scanf("%d%d", x + i, y + i);
		ta[i] = dis(0, i) - dis(2, i);
		tb[i] = dis(1, i) - dis(2, i);
		if(ta[i] < ta[mina]) mina = i;
		if(tb[i] < tb[minb]) minb = i;
		sum += 2 * dis(2, i);
	}
	double cnta = 1e9, cntb = 1e9;
	for(int i = 3; i < n + 3; i++){
		if(i != mina) cnta = min(cnta, tb[i]);
		if(i != minb) cntb = min(cntb, ta[i]);
	}
	sum += min(min(cnta + ta[mina], ta[mina]), min(cntb + tb[minb], tb[minb]));
	printf("%.10f\n", sum);
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