#include <stdio.h>
#include <vector>
using namespace std;
vector <int> nxt[30];
int prv[30];
char d[105][105];
int queue[105];
vector <char> ANS;
bool get_order(int st, int en, int lvl) {
	int t;
	if(st == en) return true;
	for(int i = st; i <= en; i++) {
		t = i;
		while(i < en) {
			if(d[t][lvl] != d[i+1][lvl]) break;
			i++;
		}
		if(i != en) {
			if(d[i+1][lvl] == 0) return false;
			if(d[i][lvl] == 0) continue;
			nxt[d[i][lvl]-'a'].push_back(d[i+1][lvl]-'a');
			prv[d[i+1][lvl]-'a']++;
		}
		if(!get_order(t, i, lvl+1)) return false;
	}
	return true;
}
int main() {
	int N, i, t;
	scanf("%d", &N);
	for(i = 0; i < N; i++) scanf("%s", d[i]);
	if(!get_order(0,N-1,0)) {
		printf("Impossible");
		return 0;
	}
	int st = 1, en = 1;
	for(i = 0; i < 26; i++) {
		if(prv[i] == 0) {
			queue[en] = i;
			en++;
		}
	}
	while(st < en) {
		t = queue[st];
		for(i = 0; i < nxt[t].size(); i++) {
			prv[nxt[t][i]]--;
			if(prv[nxt[t][i]] == 0) {
				queue[en] = nxt[t][i];
				en++;
			}
		}
		nxt[t].clear();
		ANS.push_back(queue[st]+'a');
		st++;
	}
	if(en != 27) printf("Impossible");
	else for(i = 0; i < 26; i++) printf("%c", ANS[i]);
	return 0;
}