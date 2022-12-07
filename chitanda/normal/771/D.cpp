#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int N;
char s[100];
int f[80][80][80][3];
int p[3][80][3];

inline void ckmin(int &a, int b){
	(a > b) && (a = b);
}

int main(){
	scanf("%d", &N);
	scanf("%s", s + 1);
	int n[3] = {0};
	for(int i = 1; i <= N; ++i){
		static int t;
		if(s[i] == 'V') ++n[0], t = 0;
		else if(s[i] == 'K') ++n[1], t = 1;
		else ++n[2], t = 2;
		memcpy(p[t][n[t]], n, sizeof(n));
	}

	memset(f, 127, sizeof(f));
	f[0][0][0][2] = 0;
	for(int i = 0; i <= n[0]; ++i)
		for(int j = 0; j <= n[1]; ++j)
			for(int k = 0; k <= n[2]; ++k){
				int w[] = {i, j, k}; 
				for(int la = 0; la < 3; ++la)
					if(f[i][j][k][la] < 1e9)
					for(int nla = 0; nla < 3; ++nla)
						if((la != 0 || nla != 1) && w[nla] + 1 <= n[nla]){
							++w[nla];
							int cost = max(0, p[nla][w[nla]][0] - w[0]) + max(0, p[nla][w[nla]][1] - w[1]) + max(0, p[nla][w[nla]][2] - w[2]);
							ckmin(f[w[0]][w[1]][w[2]][nla], f[i][j][k][la] + cost);
							--w[nla];
						}
			}
	int res = 1e9;
	for(int la = 0; la < 3; ++la)
		ckmin(res, f[n[0]][n[1]][n[2]][la]);
	printf("%d\n", res);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}