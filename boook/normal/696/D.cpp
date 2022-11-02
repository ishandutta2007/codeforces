#include <bits/stdc++.h>
using namespace std;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define int long long
#define INF 100000000000000000LL

int tr[300][26] , f[300] , v[300] , pos = 0;
void insert(string s , int val , int now = 0){
	REP(i , 0 , s.size()){
		int &to = tr[now][s[i] - 'a'];
		now = to ? to : to = ++pos;
	}
	v[now] += val;
}
void getac(){
	queue<int> qu;
	REP(i , 0 , 26) if(tr[0][i]) qu.push(tr[0][i]);
	while(qu.size()){
		int now = qu.front(); qu.pop();
		REP(i , 0 , 26){
			int to = tr[now][i] , tmp;
			if(to == 0) tr[now][i] = tr[f[now]][i];
			else {
				qu.push(to) , tmp = f[now];
				while(tmp && tr[tmp][i] == 0) tmp = f[tmp];
				f[to] = tr[tmp][i];
				v[to] += v[f[to]];
			}
		}
	}
}
vector<vector<int>> operator * (vector<vector<int>> a , vector<vector<int>> b){
	vector<vector<int>> c(pos + 1 , vector<int>(pos + 1 , -INF));
	REP(i , 0 , pos + 1) REP(j , 0 , pos + 1) REP(k , 0 , pos + 1)
		c[i][j] = max(c[i][j] , a[i][k] + b[k][j]);
	return c;
}
vector<vector<int>> ppow(vector<vector<int>> a , int k){
	if(k == 1) return a;
	if(k % 2 == 0) return ppow(a * a , k >> 1);
	if(k % 2 == 1) return ppow(a * a , k >> 1) * a;
}
int n , m , x[300];
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1){
    	string s;
    	cin >> s;
    	insert(s , x[i]);
    }
    getac();
    vector<vector<int>> a(pos + 1 , vector<int>(pos + 1 , -INF));
    REP(i , 0 , pos + 1) REP(j , 0 , 26) a[i][tr[i][j]] = v[tr[i][j]];
    a = ppow(a , m);
    int ans = 0;
    REP(i , 0 , pos + 1) ans = max(ans , a[0][i]);
    cout << ans << endl;
    return 0;
}