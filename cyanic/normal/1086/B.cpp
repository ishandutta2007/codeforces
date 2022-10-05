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

const int N=1000005;
int deg[N],n,x,y;
double s;

int main(){
	scanf("%d%lf",&n,&s);
	if(n==2)return printf("%.10lf\n",s),0;
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		deg[x]++,deg[y]++;
	}
	int cnt=0;
	rep(i,1,n)
		if(deg[i]==1)++cnt;
	printf("%.10lf\n",s/cnt*2);
	return 0;
}