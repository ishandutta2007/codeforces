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
#define rep0(i,n) REP(i,0,n-1)
#define rep(i,n) REP(i,1,n)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
const int N=107;
const int INF=1e9+7;
int n;
struct pir{int x,y;}p[N];
string s[N];
bool cmp(pir s,pir t){return s.x<t.x;}
bool sub(pir u,pir v){
	rep0(i,v.x-u.x+1){
		bool flag=1;
		rep0(j,u.x)if(s[u.y][j]!=s[v.y][i+j]){flag=0; break;}
		if(flag)return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		cin>>s[i];
		p[i].x=s[i].length();
		p[i].y=i;
	}
	sort(p+1,p+n+1,cmp);
	rep(i,n-1)if(sub(p[i],p[i+1])){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	rep(i,n)cout<<s[p[i].y]<<endl;
	return 0;
}