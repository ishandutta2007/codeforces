#include<bits/stdc++.h>
using namespace std;
int N, M, X, Y, F, H, i, j, D[3001][3001], s1, t1, l1, s2, t2, l2;
vector <int> V[3001];
queue <int> Q;
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	for (i=0;i<M;i++) {
		cin>>X>>Y;
		V[X].push_back(Y);
		V[Y].push_back(X);
	}
	for (i=1;i<=N;i++) {
		Q.push(i);
		while (!Q.empty()) {
			F=Q.front();
			Q.pop();
			for (j=0;j<V[F].size();j++) {
				if (D[i][V[F][j]]==0&&V[F][j]!=i) {
					Q.push(V[F][j]);
					D[i][V[F][j]]=D[i][F]+1;
				}
			}
		}
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	if (D[s1][t1]>l1) {
		cout<<-1<<'\n';
		return 0;
	}
	if (D[s2][t2]>l2) {
		cout<<-1<<'\n';
		return 0;
	}
	H=D[s1][t1]+D[s2][t2];
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			X=min(D[i][s1],D[j][s1])+min(D[i][t1],D[j][t1]);
			Y=min(D[i][s2],D[j][s2])+min(D[i][t2],D[j][t2]);
			if (X+D[i][j]<=l1&&Y+D[i][j]<=l2) {
				H=min(H,X+Y+D[i][j]);
			}
		}
	}
	cout<<M-H<<'\n';
}