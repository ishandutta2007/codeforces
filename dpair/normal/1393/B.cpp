#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[100010], x;
int cnt2, cnt4, cnt6, cnt8;

inline void add(int u, int val){
	if(val > 0){
		cnt[u] ++;
		if(cnt[u] == 8) cnt8 ++;
		if(cnt[u] == 6) cnt6 ++;
		if(cnt[u] == 4) cnt4 ++;
		if(cnt[u] == 2) cnt2 ++;
	}
	else{
		if(cnt[u] == 8) cnt8 --;
		if(cnt[u] == 6) cnt6 --;
		if(cnt[u] == 4) cnt4 --;
		if(cnt[u] == 2) cnt2 --;
		cnt[u] --;
	}
}

inline bool check(){
	if(cnt4 && cnt2 > 2) return 1;
	if(cnt4 >= 2) return 1;
	if(cnt6 && cnt2 > 1) return 1;
	if(cnt8) return 1;
	return 0;
}

int main(){
	scanf("%d", &n);
	for (register int i = 1;i <= n;i ++){
		scanf("%d", &x);
		add(x, 1);
	}
	int t;scanf("%d", &t);
	while(t --){
		char s[10];
		scanf("%s %d", s, &x);
		if(s[0] == '+') add(x, 1);
		else add(x, -1);
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
}