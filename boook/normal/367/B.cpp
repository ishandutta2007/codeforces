/*input
6 3 2
1 3 2 2 3 1
1 2 3
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , d , a[MAX] , b[MAX];
int goal[MAX] , cnt[MAX];
vector<int> uni , ans;
int32_t main(){
	cin >> n >> m >> d;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , m + 1) cin >> b[i];
	REP(i , 1 , n + 1) uni.pb(a[i]);
	REP(i , 1 , m + 1) uni.pb(b[i]);

	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1) a[i] = lower_bound(ALL(uni) , a[i]) - uni.begin();
	REP(i , 1 , m + 1) b[i] = lower_bound(ALL(uni) , b[i]) - uni.begin();

	uni.clear();
	REP(i , 1 , m + 1) uni.pb(b[i]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());

	REP(i , 1 , m + 1) goal[b[i]] ++;

	// DBGG("goal = " , uni.size());
	// REP(i , 1 , n + 1) cout << a[i] << " "; cout << endl;
	// REP(i , 1 , m + 1) cout << b[i] << " "; cout << endl;

	REP(i , 1 , d + 1){
		int fr = i , ba = i - d , siz = 0 , dis = uni.size();
		while(ba + d <= n){
			ba += d , siz ++;
			if(cnt[a[ba]] != goal[a[ba]]) dis --;

			cnt[a[ba]] ++;

			if(cnt[a[ba]] != goal[a[ba]]) dis ++;

			if(siz > m){
				if(cnt[a[fr]] != goal[a[fr]]) dis --;
				cnt[a[fr]] --;
				if(cnt[a[fr]] != goal[a[fr]]) dis ++;
				fr += d , siz --;
			}
			if(siz == m && dis == 0) ans.pb(fr);
			// DB4("fr = " , fr , ba , dis);
		}
		while(fr <= n){
			if(cnt[a[fr]] != goal[a[fr]]) dis --;
			cnt[a[fr]] --;
			if(cnt[a[fr]] != goal[a[fr]]) dis ++;
			fr += d , siz --;
		}
		assert(siz == 0);
	}
	sort(ALL(ans));
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}