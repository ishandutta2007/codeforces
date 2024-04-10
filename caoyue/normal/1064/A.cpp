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
const int N=7;
const int INF=1e9+7;
int a,b,c,ans=INF; 
int main(){
	scanf("%d%d%d",&a,&b,&c);
	rep0(i,200){
		rep0(j,200){
			rep0(k,200){
				int x=a+i,y=b+j,z=c+k;
				if(x+y>z&&x+z>y&&y+z>x)ans=min(ans,i+j+k);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}