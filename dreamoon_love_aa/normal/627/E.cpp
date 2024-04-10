#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define REP(i,n) for (int i=1;i<=(n);++i)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define ROF(i,a,b) for (int i=(a);i>=(b);--i)
#define FEC(p,u) for (edge*p=head[u];p;p=p->nxt)
using namespace std;
typedef long long LL;

int n, m, k, bl[3003][12], br[3003][12], cl[12], cr[12], tl[12], tr[12];
LL ans;
char a[3003][3003];
int nxt[4][3003][3003],dp[3003][3003];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];
}
void work(int u, int d, int l, int r){
    if(get(u,l,d,r)<k)return;
	if (d-u > r-l){
		int m(u+d>>1);
		FOR(i,l,r){
			int t(0);
			bl[i][0] = m;
            for(int j=nxt[0][m+1][i];j>=u;j=nxt[0][j][i]){
			//ROF(j,m,u){
				bl[i][++t] = j;
				if (t == k) break;
			}
			while (t < k) bl[i][++t] = u-1;
			t = 0;
			br[i][0] = m;
            for(int j=nxt[1][m][i];j<=d;j=nxt[1][j][i]){
			//FOR(j,m+1,d){
				br[i][++t] = j;
				if (t == k) break;
			}
			while (t < k) br[i][++t] = d+1;
		}
		FOR(i,l,r){
			cl[0] = cr[0] = m;
			REP(t,k) cl[t] = u-1, cr[t] = d+1;
			FOR(j,i,r){
				FOR(t,0,k) tl[t] = cl[t], tr[t] = cr[t];
				int p(1), q(1);
				REP(t,k)
					if (tl[p] > bl[j][q]) cl[t] = tl[p++]; else cl[t] = bl[j][q++];
				p = 1, q = 1;
				REP(t,k)
					if (tr[p] < br[j][q]) cr[t] = tr[p++]; else cr[t] = br[j][q++];
                cl[k+2] = u-1;
                cr[k+2] = d+1;
				FOR(t,0,k-1) ans += (cl[t]-cl[t+1])*(cr[k+2]-cr[k-t]);
                ans+=(cl[k]-cl[k+2])*(cr[k+2]-cr[0]);
			}
		}
		if (u < m) work(u, m-1, l, r);
		if (m < d) work(m+1, d, l, r);
	}else{
		int m(l+r>>1);
		FOR(i,u,d){
			int t(0);
			bl[i][0] = m;
            for(int j=nxt[2][i][m+1];j>=l;j=nxt[2][i][j]){
			//ROF(j,m,l){
				bl[i][++t] = j;
				if (t == k) break;
			}
			while (t < k) bl[i][++t] = l-1;
			t = 0;
			br[i][0] = m;
            for(int j=nxt[3][i][m];j<=r;j=nxt[3][i][j]){
			//FOR(j,m+1,r){
				br[i][++t] = j;
				if (t == k) break;
			}
			while (t < k) br[i][++t] = r+1;
		}
		FOR(i,u,d){
			cl[0] = cr[0] = m;
			REP(t,k) cl[t] = l-1, cr[t] = r+1;
			FOR(j,i,d){
				FOR(t,0,k) tl[t] = cl[t], tr[t] = cr[t];
				int p(1), q(1);
				REP(t,k)
					if (tl[p] > bl[j][q]) cl[t] = tl[p++]; else cl[t] = bl[j][q++];
				p = 1, q = 1;
				REP(t,k)
					if (tr[p] < br[j][q]) cr[t] = tr[p++]; else cr[t] = br[j][q++];
				//FOR(t,0,k) ans += (cl[t]-cl[t+1])*(cr[k-t+1]-cr[k-t]);
                
                cl[k+2] = l-1;
                cr[k+2] = r+1;
				FOR(t,0,k-1) ans += (cl[t]-cl[t+1])*(cr[k+2]-cr[k-t]);
                ans+=(cl[k]-cl[k+2])*(cr[k+2]-cr[0]);
			}
		}
		if (l < m) work(u, d, l, m-1);
		if (m < r) work(u, d, m+1, r);
	}
}
int main(){
    int grid_n;
	scanf("%d%d%d%d", &n, &m, &grid_n, &k);
	REP(i,grid_n){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]='1';
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)dp[i][j]=dp[i][j-1]+(a[i][j]=='1');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)dp[i][j]+=dp[i-1][j];
    for(int i=1;i<=m;i++){
        nxt[0][1][i]=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]=='1')nxt[0][j+1][i]=j;
            else nxt[0][j+1][i]=nxt[0][j][i];
        }
        nxt[1][n][i]=n+1;
        for(int j=n;j>0;j--){
            if(a[j][i]=='1')nxt[1][j-1][i]=j;
            else nxt[1][j-1][i]=nxt[1][j][i];
        }
    }
    for(int j=1;j<=n;j++){
        nxt[2][j][1]=0;
        for(int i=1;i<=m;i++){
            if(a[j][i]=='1')nxt[2][j][i+1]=i;
            else nxt[2][j][i+1]=nxt[2][j][i];
        }
        nxt[3][j][m]=m+1;
        for(int i=m;i>0;i--){
            if(a[j][i]=='1')nxt[3][j][i-1]=i;
            else nxt[3][j][i-1]=nxt[3][j][i];
        }
    }
	work(1, n, 1, m);
	printf("%I64d\n", ans);
	return 0;
}