#include <bits/stdc++.h>

using namespace std;

char ch[]="AOXaox";

const int NN = 1<<12;

int cnt[NN], p[15], q[NN], qq[NN];
int val[531441], pp[531441][12];
int pat[2][46656][64];
int adj[6][2]={{2, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 2}, {1, 0}};

int main() {
	int w, n, m, u;
	cin>>w>>n>>m;
	for (int i=0; i<n; i++) scanf("%d", &u), cnt[u]++;
	for (int i=p[0]=1; i<=w; i++) p[i]=p[i-1]*3;

	for (int i=0; i<p[w]; i++) {
		for (int j=0, k=i; j<w; j++) pp[i][j]=k%3, k/=3;
	}

	for (int i=0; i<p[w]; i++) {
		int t = 0, tt = 0;
		for (int j=0; j<w; j++) 
			if (pp[i][j]==2) t|=1<<j;
			else tt |= pp[i][j]<<j;
		val[i]+=cnt[tt];
		for (int r = t; r; r=t&(r-1)) val[i]+=cnt[tt^r];
	}

	for (int i=0; i<1<<w; i++) q[i]=i>>6, qq[i]=i&63;

	int num = 0;
	for (int len=1, ed = 6; len<7; ed=ed*6, len++) {
		if (w<=6) {
			if (len!=w) continue;
			num = 0;
		} else {
			if (len!=w-6 && len!=6) continue;
			if (len==w-6) num=0;
			else num=1;
		}
		for (int j=0; j<ed; j++) {
			static int tp[11];
			for (int t=0, u=j; t<len; t++) tp[t]=u%6, u/=6;
			for (int r=0; r<1<<len; r++) {
				for (int i=0; i<len; i++) {
					int u=adj[tp[i]][(r>>i)&1];
					if (u==-1) {
						pat[num][j][r]=-1;
						break;
					}
					pat[num][j][r]+=p[i]*u;
				}
			}
		}
	}

	if (w==12) memcpy(pat[1], pat[0], sizeof pat[0]);
	if (w>6) for (int i=0; i<p[w-6]<<w-6; i++) for (int j=0; j<1<<w-6; j++) if (~pat[0][i][j]) pat[0][i][j]*=p[6];

	char s[15];
	while (m--) {
		scanf("%s", s);
		if (w<=6) {
			int st = 0;
			for (int i=0; i<w; i++) st=st*6+(strchr(ch, s[i])-ch);
			int ans = 0;
			for (int i=0; i<1<<w; i++) {
				if (pat[0][st][i]==-1 || cnt[i]==0) continue;
				ans += val[pat[0][st][i]]*cnt[i];
			}
			printf("%d\n", ans);
			continue;
		}
		int st1 = 0, st2 = 0;
		for (int i=0; i<w-6; i++) st1=st1*6+(strchr(ch, s[i])-ch);
		for (int i=w-6; i<w; i++) st2=st2*6+(strchr(ch, s[i])-ch);
		int ans = 0;
		for (int i=0; i<1<<w; i++) {
			if (pat[0][st1][q[i]]==-1 || pat[1][st2][qq[i]]==-1 || cnt[i]==0) continue;
			ans += val[pat[0][st1][q[i]]+pat[1][st2][qq[i]]]*cnt[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}