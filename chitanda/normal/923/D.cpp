#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

char s[100100], t[100100];
int p[100100], q[100100];
int preA1[100100], preA2[100100];

int main(){
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for(int i = 1; s[i]; ++i){
		p[i] = p[i - 1];
		if(s[i] != 'A') ++p[i];
		else preA1[i] = preA1[i - 1] + 1;
	}
	for(int i = 1; t[i]; ++i){
		q[i] = q[i - 1];
		if(t[i] != 'A') ++q[i];
		else preA2[i] = preA2[i - 1] + 1;
	}
	int Q, a, b, c, d;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int tmp1 = p[b] - p[a - 1];
		int tmp2 = q[d] - q[c - 1];
		int sufA1 = min(b - a + 1, preA1[b]);
		int sufA2 = min(d - c + 1, preA2[d]);
		bool flag = 1;
		if(sufA1 < sufA2) flag = 0;
		else{
			int res = sufA1 - sufA2;
			res %= 3;
			if(res) tmp1 += 2;
		}
		if(sufA1 == sufA2 && !tmp1 && tmp2) flag = 0;
		if(tmp1 <= tmp2 && (tmp2 - tmp1) % 2 == 0 && flag) putchar('1');
		else putchar('0');
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}