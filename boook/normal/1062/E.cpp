/*input
11 5
1 1 3 3 3 4 2 7 7 6
4 6
4 8
1 11
9 11
8 11
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define PII pair<int , int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define DBGG(i , j) cout << i << " " << j << endl
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)
#define MAX 300900



int n , m , x[MAX] , p[MAX];
vector<int> v[MAX];
int in[MAX] , ot[MAX] , po = 0 , dep[MAX] , val[MAX];
struct N{
	PII sml , big;
	int dep;
} st[MAX * 4];

N pull(N a , N b){
	N ans;
	ans.dep = min(a.dep , b.dep);
	ans.sml = min(a.sml , b.sml);
	ans.big = max(a.big , b.big);
	return ans;
}
void build(int now , int l , int r){
	if(l == r){
		st[now].sml = mp(val[l] , l);
		st[now].big = mp(val[l] , l);
		st[now].dep = dep[l];
	}
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		st[now] = pull(st[ls] , st[rs]);
	}
}
N query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return st[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
void DFS(int now , int deep){
	// DBGG("now = " , now);
    val[now] = po;
    for(auto to : v[now]){
    	dep[++po] = deep + 1;
    	DFS(to , deep + 1);
    	dep[++po] = deep;
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 2 , n + 1) cin >> p[i];
    REP(i , 1 , n + 1) v[p[i]].pb(i);
    DFS(1 , 0);

    build(1 , 0 , po);
    // REP(i , 1 , po + 1) cout << dep[i] << " "; cout << endl;
    // REP(i , 1 , po + 1) cout << in[i] << " "; cout << endl;
    REP(i , 1 , m + 1){
        int v1 , v2;
        cin >> v1 >> v2;
        N res = query(1 , 0 , po , v1 , v2);
        // cout << "get = ";
        PII ans = mp(-1 , -1);
        for(auto to : {res.sml.S , res.big.S}){
        	N tmp;
        		 if(to == v1) tmp = query(1 , 0 , po , v1 + 1 , v2);
        	else if(to == v2) tmp = query(1 , 0 , po , v1 , v2 - 1);
        	else tmp = pull(query(1 , 0 , po , v1 , to - 1) , 
        					query(1 , 0 , po , to + 1 , v2));

        	int ql = tmp.sml.F , qr = tmp.big.F;
        	ans = max(ans , mp(query(1 , 0 , po , ql , qr).dep , to));
        	// cout << to << " ";
        }
        cout << ans.S << " " << ans.F << endl;
        // cout << endl;
    }
    return 0;
}