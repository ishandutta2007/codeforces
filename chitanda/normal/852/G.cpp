#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int cnt[100100 * 50];
int tag[100100 * 50];
int go[100100 * 50][5];
char s[100];
int root, tot;
int idx;

void insert(){
	int now = root;
	for(int i = 0; s[i]; ++i){
		if(!go[now][s[i] - 'a'])
			go[now][s[i] - 'a'] = ++tot;
		now = go[now][s[i] - 'a'];
	}
	++cnt[now];
}

int work(int t, int i){
	if(!t) return 0;
	if(!s[i]){
		if(tag[t] == idx) return 0;
		else tag[t] = idx;
		return cnt[t];
	}
	if(s[i] == '?'){
		int res = work(t, i + 1);
		for(int j = 0; j < 5; ++j)
			res += work(go[t][j], i + 1);
		return res;
	}else return work(go[t][s[i] - 'a'], i + 1);
}

int main(){
	scanf("%d%d", &n, &m);
	root = tot = 1;
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		insert();
	}
	while(m--){
		scanf("%s", s);
		++idx;
		int ans = work(1, 0);
		printf("%d\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}