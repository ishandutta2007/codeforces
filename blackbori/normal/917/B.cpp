#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int D[111][111][33];
vector <pii> V[111];
int n,m;

int F(int p,int q,int r)
{
	if(D[p][q][r]) return D[p][q][r];
	
	int ret = 0;
	
	for(pii t: V[p]){
		if(t.second >= r) ret |= (F(q,t.first,t.second) - 1);
	}
	
	ret = 2 - ret;
	
	return D[p][q][r] = ret;
}

int main()
{
	int i,j,a,b,c;
	char st[5];
	
	scanf("%d%d",&n,&m);
	
	for(i=0;i<m;i++){
		scanf("%d%d%s",&a,&b,st);
		V[a].push_back(pii(b,st[0]-'a'));
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%c",F(i,j,0)+'A' - 1);
		}
		printf("\n");
	}
	
	return 0;
}