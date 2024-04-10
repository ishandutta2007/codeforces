#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 200000 + 5;

int N;
int col[MN];
vector<int> E[MN];
vector<int> ans;

void v(int n){
	ans.push_back(n+1);
	col[n] ^= 1;
}

void dfs(int n, int bef){
	v(n);
	for(auto &t: E[n])if(t!=bef){
		dfs(t, n);
		v(n);
		if(col[t] == 0){
			v(t); v(n);
		}
	}
}

int main(){
	scanf("%d",&N);
	bool flag = true;
	for(int i=0;i<N;i++){
		scanf("%d",&col[i]);
		if(col[i]==-1) col[i]=0, flag = false;
	}
	if(flag){
		puts("1");
		return 0;
	}
	col[0] ^= 1;
	int ee = -1;
	for(int i=0;i<N-1;i++){
		II(a)II(b); a--,b--;
		E[a].push_back(b), E[b].push_back(a);
		if(a==0 || b==0) ee = a+b;
	}
	dfs(0, -1);
	if(col[0] == 0){
		v(ee); v(0); v(ee);
	}
	for(auto &n: ans) printf("%d ",n);
	return 0;
}