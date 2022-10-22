//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int T,pos1,pos2,ans;
int sum[26][MAXN],pos[26][MAXN],lens,lent;
char s[MAXN],t[MAXN];

inline bool cnt(int id,char c) {return (sum[c - 'a'][id] > 0);}

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%s",t + 1);
		scanf("%s",s + 1);
		lens = strlen(s + 1),lent = strlen(t + 1);
		pos1 = pos2 = 1;
		ans = 0;
		for(register int i = 0;i < 26; ++i) {
			sum[i][lent + 1] = 0;
			pos[i][lent + 1] = lent + 1;
		}
		for(register int i = lent;i; --i) {
			for(register int c = 0;c < 26; ++c) {
				sum[c][i] = sum[c][i + 1];
				pos[c][i] = pos[c][i + 1];
			}
			sum[t[i] - 'a'][i]++;
			pos[t[i] - 'a'][i] = i;
		}
		for(register int i = 1;i <= lens; ++i) 
			if(!sum[s[i] - 'a'][1]) {ans = -1; break;}
		if(ans == -1) {printf("-1\n"); continue;}
		while(pos1 <= lens) {
			if(!cnt(pos2,s[pos1])) {ans++,pos2 = 1; continue;}
			while(t[pos2] != s[pos1] && pos[s[pos1] - 'a'][pos2] <= lent) pos2 = pos[s[pos1] - 'a'][pos2];
			pos1++,pos2++;
			if(pos1 > lens) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}