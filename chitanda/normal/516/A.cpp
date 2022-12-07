#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, cnt[10];
char s[100];

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < n; ++i){
		int x = s[i] - '0';
		if(x == 2) ++cnt[2];
		if(x == 3) ++cnt[3];
		if(x == 4) cnt[2] += 2, ++cnt[3];
		if(x == 5) ++cnt[5];
		if(x == 6) ++cnt[5], ++cnt[3];
		if(x == 7) ++cnt[7];
		if(x == 8) ++cnt[7], cnt[2] += 3;
		if(x == 9) ++cnt[7], cnt[3] += 2, ++cnt[2];
	}
	for(int i = 7; i >= 2; --i)
		for(int j = 1; j <= cnt[i]; ++j)
			putchar('0' + i);
	if(!cnt[2] && !cnt[3] && !cnt[5] && !cnt[7])
		putchar('0');
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}