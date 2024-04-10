#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=(0);i<(n);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=1005;
int x[3],y[3],X,Y,now,best=1e9;

int main(){
	rep(i,0,2)scanf("%d%d",&x[i],&y[i]);
	rep(i,0,1000)rep(j,0,1000){
		now=4;
		rep(k,0,2){
			if(i==x[k]&&j==y[k])now--;
			else now+=abs(i-x[k])+abs(j-y[k])-1;
		}
		if(now<best)X=i,Y=j,best=now;
	}
	printf("%d\n",best);
	printf("%d %d\n",X,Y);
	rep(k,0,2){
		if(X==x[k]&&Y==y[k])continue;
		printf("%d %d\n",x[k],y[k]);
		rep(i,min(X,x[k])+1,max(X,x[k])-1)
			printf("%d %d\n",i,y[k]);
		rep(i,min(Y,y[k])+1,max(Y,y[k])-1)
			printf("%d %d\n",X,i);
		if(X!=x[k]&&Y!=y[k])
			printf("%d %d\n",X,y[k]);
	}
	return 0;
}