#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
char s[N];
int n;
int a[27];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	rep0(i,n)a[s[i]-'a']++;
	rep0(i,26){
		char c='a'+i;
		rep(j,a[i])putchar(c);
	}
	return 0;
}