#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
const int N=1e7+7;
int ch[N][2],s[N]; ll sum[N],ans[100][2];
signed main(){
	int n,nd=1; scanf("%d",&n); ll cnt=0;
	rep(i,1,n){
		int x,u=1; scanf("%d",&x);
		per(j,30,0){
			int c=x>>j&1;
			if (!ch[u][c]) ch[u][c]=++nd;
			ans[j][c]+=s[ch[u][c^1]],++s[u=ch[u][c]];
		}
	}
	int mnp=0; ll mn=0;
	rep(j,0,30){
		if (ans[j][0]<=ans[j][1]) mn+=ans[j][0];
		else mn+=ans[j][1],mnp+=1<<j;
	}
	printf("%lld %d\n",mn,mnp);
	return 0;
}