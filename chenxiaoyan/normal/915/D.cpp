#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define T true
#define F false
vector<int> nei[501];
int ideg[501];
bool mar[501];
int main(){
	int n,m,i;scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		nei[x].pb(y);
	}
	for(i=1;i<=n;i++){
		int j;
		fill(ideg+1,ideg+n+1,0);
		fill(mar+1,mar+n+1,F);
		queue<int> q,resq;
		for(j=1;j<=n;j++)
			for(int k=0;k<nei[j].size();k++)
				ideg[nei[j][k]]++;
//		for(j=1;j<=n;j++)cout<<ideg[j]<<" ";puts("");
		for(j=1;j<=n;j++)
			if(!ideg[j]||j==i&&ideg[j]==1)q.push(j);
		while(!q.empty()){
			int x=q.front();q.pop();
			if(mar[x])continue;
			resq.push(x);mar[x]=T;
//			cout<<x<<" ";
			for(j=0;j<nei[x].size();j++){
				int y=nei[x][j];
				ideg[y]--;
				if(!ideg[y]||y==i&&ideg[y]==1)q.push(y);
			}
		}
//		puts("");
		if(resq.size()==n)return !printf("YES");
	}
	printf("NO");
	return 0;
}
/*1
3 4
1 2
2 3
3 2
3 1
*/
/*2
5 6
1 2
2 3
3 2
3 1
2 1
4 5
*/
/*3
4 5
1 3
3 2
2 1
3 4
4 1
*/