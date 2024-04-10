#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=507;
const int INF=1e9+7;
char s[N][N];
int n;
 
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%s",s[i]+1);
	int cnt=0;
	REP(i,2,n-1){
		REP(j,2,n-1){
			if(s[i][j]=='X')
			if(s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i+1][j+1]=='X')
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}