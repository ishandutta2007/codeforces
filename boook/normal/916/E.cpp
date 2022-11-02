/*input
6 4
1 2 3 4 5 6
1 2
3 1
4 3
4 5
3 6
1 6
2 4 6 3
3 4
3 3
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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int tag[MAX * 4] , sum[MAX * 4];
int Push(int now , int l , int r){
    if(tag[now] && l != r){
        sum[ls] += 1LL * ((mid + 0) - l + 1) * tag[now];
        tag[ls] += tag[now];
        sum[rs] += 1LL * (r - (mid + 1) + 1) * tag[now];
        tag[rs] += tag[now];
        tag[now] = 0;
    }
}
int Update(int now , int l , int r , int ql , int qr , int val){
    if(ql <= l && r <= qr){
        tag[now] += val;
        sum[now] += 1LL * (r - l + 1) * val;
    }
    else {
        Push(now , l , r);
        if(ql <= mid + 0) Update(ls , l , mid + 0 , ql , qr , val);
        if(mid + 1 <= qr) Update(rs , mid + 1 , r , ql , qr , val);
        sum[now] = sum[ls] + sum[rs];
    }
}
int Query(int now , int l , int r , int ql , int qr){
	// if(now == 1) DB4(now , ql , qr , "");
    Push(now , l , r);
    if(ql <= l && r <= qr) return sum[now];
    if(qr <= mid + 0) return Query(ls , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return Query(rs , mid + 1 , r , ql , qr);
    return Query(ls , l , mid + 0 , ql , qr) + Query(rs , mid + 1 , r , ql , qr);
}

int n , m , x[MAX] , root = 1;
int in[MAX] , dep[MAX] , out[MAX] , sp[MAX][20] , po = 0;

int FA(int a , int b){
	return in[a] <= in[b] && out[a] >= out[b];
}
int LCA(int a , int b){
	if(FA(a , b)) return a;
	RREP(i , 19 , 0){
		if(FA(sp[a][i] , b) == 0) a = sp[a][i];
	}
	return sp[a][0];
}

vector<int> v[MAX];
void DFS(int now , int fa , int deep){
	sp[now][0] = fa;
	in[now] = ++po;
	dep[now] = deep;
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS(to , now , deep + 1);
	}
	out[now] = po;
}
int UU(int now , int val){
	if(root == now){
		Update(1 , 1 , n + 10 , in[1] , out[1] , val);
	}
	else if(FA(now , root)){
		Update(1 , 1 , n + 10 , in[1] , out[1] , val);
		int rr = root;
		RREP(j , 19 , 0){
			if(FA(sp[rr][j] , now) == 0) rr = sp[rr][j];
		}
		Update(1 , 1 , n + 10 , in[rr] , out[rr] , -val);
	}
	else {
		Update(1 , 1 , n + 10 , in[now] , out[now] , val);
	}
}
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}

	DFS(1 , 0 , 1) , out[0] = ++po;
	REP(j , 1 , 20){
		REP(i , 1 , n + 1){
			sp[i][j] = sp[sp[i][j - 1]][j - 1];
		}
	}
	REP(i , 1 , n + 1){
		Update(1 , 1 , n + 10 , in[i] , in[i] ,  x[i]);
	}
	REP(i , 1 , m + 1){
		int ty , now , to , v;
		cin >> ty;
		if(ty == 1) cin >> now , root = now;
		else if(ty == 2){
			cin >> now >> to >> v;
			int aa = LCA(now , to)   , ax = dep[aa];
			int bb = LCA(now , root) , bx = dep[bb];
			int cc = LCA(to , root)  , cx = dep[cc];
			if(ax >= bx && ax >= cx) UU(aa , v);
			else if(bx >= ax && bx >= cx) UU(bb , v);
			else if(cx >= ax && cx >= bx) UU(cc , v);
		}
		else if(ty == 3){
			cin >> now;
			if(root == now){
				cout << Query(1 , 1 , n + 10 , in[1] , out[1]) << endl;
			}
			else if(FA(now , root)){
				int rr = root;
				RREP(j , 19 , 0){
					if(FA(sp[rr][j] , now) == 0) rr = sp[rr][j];
				}
				cout << Query(1 , 1 , n + 10 , in[1] , out[1]) 
				      - Query(1 , 1 , n + 10 , in[rr] , out[rr]) << endl;
			}
			else {
				cout << Query(1 , 1 , n + 10 , in[now] , out[now]) << endl;
			}
		}
	}
    return 0;
}