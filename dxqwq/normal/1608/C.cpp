#include <bits/stdc++.h>
#define Mashu cout << "UUZ has eaten it." << endl
#define ll long long
using namespace std;

struct ran{
	int x, i;
};

ran a[100010], b[100010];
int chen[100010], yukari[100010];
int win[100010];

bool cmp(ran x, ran y){
	return x.x < y.x;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		a[0].i = 0;
		b[0].i = 0;
		for (int i = 1; i <= n; i++){
			win[i] = 0;
		}
		int MXA = 0, MXAi = 0, MXB = 0, MXBi = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i].x;
			a[i].i = i;
			if (a[i].x > MXA){
				MXA = a[i].x;
				MXAi = i;
			}
			chen[i] = a[i].x;
		}
		for (int i = 1; i <= n; i++){
			cin >> b[i].x;
			b[i].i = i;
			if (b[i].x > MXB){
				MXB = b[i].x;
				MXBi = i;
			}
			yukari[i] = b[i].x;
		}
		int mnb = b[MXAi].x, mna = a[MXBi].x, qwq = n, qaq = n;
		sort(a + 1, a + 1 + n, cmp);
		sort(b + 1, b + 1 + n, cmp);
		int ok = 1;
		while (ok){
			ok = 0;
			while (a[qwq].x >= mna && qwq >= 1){
				ok = 1;
				win[a[qwq].i] = 1;
				mna = min(mna, chen[a[qwq].i]);
				mnb = min(mnb, yukari[a[qwq].i]);
				qwq--;
			}
			while (b[qaq].x >= mnb && qaq >= 1){
				ok = 1;
				win[b[qaq].i] = 1;
				mna = min(mna, chen[b[qaq].i]);
				mnb = min(mnb, yukari[b[qaq].i]);
				qaq--;
			}
		}
		for (int i = 1; i <= n; i++){
			putchar(48+win[i]);
		}
		puts("");
	}
	return 0;
	Mashu;
}
/*
3
4
1 2 3 4
1 2 3 4
4
11 12 20 21
44 22 11 30
1
1000000000
1000000000
*/