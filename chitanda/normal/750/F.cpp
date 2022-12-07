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

int h, n;
bool tag[200];
int a[200][5];

void walk(int t){
	printf("? %d\n", t);
	fflush(stdout);
	tag[t] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a[t] + i);
}

int work(int hh, int t){
	if (hh == 1) return t;

	if (hh == 2){
		if (tag[a[t][1]]) swap(a[t][1], a[t][2]);
		walk(a[t][1]);
		if (n == 2) return a[t][1];
		else{
			for(int i = 1; i <= 3; ++i)
				if(!tag[a[t][i]]) return a[t][i];
		}
	}

	if (hh == 3){
		if (tag[a[t][1]]) swap(a[t][1], a[t][2]);
		walk(a[t][1]);
		if (n == 1){
			for(int i = 1; i <= 3; ++i)
				if (!tag[a[t][i]]){
					walk(a[t][i]);
					return work(hh - 1, a[t][i]);
				}
		}
		int k = a[t][1];
		if (tag[a[k][1]]) swap(a[k][1], a[k][2]);
		walk(a[k][1]);
		if (n == 2) return a[k][1];
		else{
			for(int i = 1; i <= 3; ++i)
				if(!tag[a[k][i]]){
					walk(a[k][i]);
					if (n == 2) return a[k][i];
					else{
						for(int i = 1; i <= 3; ++i)
							if(!tag[a[t][i]]){
								walk(a[t][i]);
								return work(hh - 1, a[t][i]);
							}
					}
			}
		}
	}
	/*
	if (hh == h){
		work(hh - 1, a[t][1]);
	}
 
	if (hh == h - 1){
		if (tag[a[t][1]]) swap(a[t][1], a[t][2]);
		walk(a[t][1]);
		if (n == 1){
			for(int i = 1; i <= 3; ++i)
				if(!tag[a[t][i]]){
					walk(a[t][i]);
					return work(hh - 1, a[t][i]);
				}
		}else{
			return work(hh - 1, a[t][1]);
		}
	}
	*/

	vector<int> q;
	int last = t;
	do{
		for(int i = 2; i <= 3; ++i)
			if(!tag[a[last][i]]) swap(a[last][i], a[last][1]);
		q.pb(a[last][1]);
		walk(a[last][1]);
		last = a[last][1];
		if (hh == 4 && h == 7 && q.size() == 6) { n = 3; q.pb(0); break; }
	}while(n == 3);
	if (n == 2) return last;
	int m = q.size();
	int k = t;
	if (m > h - hh) k = q[(m + h - hh) / 2 - (h - hh + 1)];
	for(int i = 1; i <= 3; ++i)
		if (!tag[a[k][i]]){
			int nh = h - (m + h - hh) / 2 - 1;
			if (nh > 1) walk(a[k][i]);
			return work(nh, a[k][i]);
		}
}

int work(){
	walk(1);
	if (n == 2) return 1;
	
	if (n == 3){
		vector<int> q;
		q.pb(1);
		int last = 1;
		do{
			if (tag[a[last][1]]) swap(a[last][1], a[last][2]);
			q.pb(a[last][1]);
			walk(a[last][1]);
			last = a[last][1];
		}while(n == 3);
		if (n == 2) return last;
		reverse(all(q));

		swap(a[1][1], a[1][2]);
		last = 1;
		do{
			if (tag[a[last][1]]) swap(a[last][1], a[last][2]);
			q.pb(a[last][1]);
			walk(a[last][1]);
			last = a[last][1];
		}while(n == 3);
		if (n == 2) return last;
 
		int m = q.size();
		int t = q[m / 2];
		for(int i = 1; i <= 3; ++i){
			if (!tag[a[t][i]]){
				walk(a[t][i]);
				return work(h - m / 2 - 1, a[t][i]);
			}
		}
		
	}else{
		if (h > 2) walk(a[1][1]);
		return work(h - 1, a[1][1]);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while(t--){
		memset(tag, 0, sizeof(tag));
		memset(a, 0, sizeof(a));
		scanf("%d", &h);
		printf("! %d\n", work());
		fflush(stdout);
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