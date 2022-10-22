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
const int N=7;
const int INF=1e9+7;

int main(){
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	if(x>a){puts("NO"); return 0;}
	if(x+y>a+b){puts("NO"); return 0;}
	if(x+y+z>a+b+c){puts("NO"); return 0;}
	puts("YES"); 
	return 0;
}