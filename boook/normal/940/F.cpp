/*input
10 1
1 3 4 3 2 2 3 4 4 4
1 1 10
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300090
#define INF 0x3f3f3f3f

int mex[MAX] , cnt[MAX];

int n , m , x[MAX] , a[MAX];
int q[MAX][2] , t[MAX] , qpo = 0;
int c[MAX][3] , cpo = 0;
int sol[MAX] , N;
int ans[MAX];
int cmp(int a , int b){
	if(q[a][0] / N != q[b][0] / N) return q[a][0] < q[b][0];
	if(q[a][1] / N != q[b][1] / N) return q[a][1] < q[b][1];
	return t[a] < t[b];
}
inline void ADD(int now){
	assert(now <= MAX);
	mex[cnt[now]] --;
	cnt[now] ++;
	mex[cnt[now]] ++;
}
inline void STR(int now){
	assert(now <= MAX);
	mex[cnt[now]] --;
	cnt[now] --;
	mex[cnt[now]] ++;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	N = pow(n , 2.0 / 3) , N = max(1 , N);
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) a[i] = x[i];
	REP(i , 1 , m + 1){
		int ty , l , r;
		cin >> ty >> l >> r;
		if(ty == 1) q[qpo][0] = l , q[qpo][1] = r , t[qpo] = cpo , qpo ++;
		if(ty == 2){
			cpo ++;
			c[cpo][0] = x[l];
			x[l] = r;
			c[cpo][1] = x[l];
			c[cpo][2] = l;
		}
	}

	vector<int> uni;
	REP(i , 1 , n + 1) uni.pb(a[i]);
	REP(i , 1 , cpo + 1) uni.pb(c[i][0]) , uni.pb(c[i][1]);

	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1) a[i] = lower_bound(ALL(uni) , a[i]) - uni.begin();
	REP(i , 1 , cpo + 1) REP(j , 0 , 2) c[i][j] = lower_bound(ALL(uni) , c[i][j]) - uni.begin();

	REP(i , 0 , qpo) sol[i] = i;
	sort(sol , sol + qpo , cmp);

	int l = 1 , r = 0 , tt = 0;
    REP(i , 0 , qpo){
    	int now = sol[i];

    	while(t[now] > tt){
    		tt ++;
    		if(l <= c[tt][2] && c[tt][2] <= r) STR(a[c[tt][2]]);
    		a[c[tt][2]] = c[tt][1];
    		if(l <= c[tt][2] && c[tt][2] <= r) ADD(a[c[tt][2]]);
    	}
    	while(t[now] < tt){
    		if(l <= c[tt][2] && c[tt][2] <= r) STR(a[c[tt][2]]);
    		a[c[tt][2]] = c[tt][0];
    		if(l <= c[tt][2] && c[tt][2] <= r) ADD(a[c[tt][2]]);
    		tt --;
    	}

    	while(q[now][0] < l) ADD(a[-- l]);
    	while(l < q[now][0]) STR(a[l ++]);
    	while(q[now][1] < r) STR(a[r --]);
    	while(r < q[now][1]) ADD(a[++ r]);

    	REP(j , 1 , MAX) if(mex[j] == 0){
    		ans[now] = j;
    		break;
    	}
    }
    REP(i , 0 , qpo) cout << ans[i] << endl;
    return 0;
}