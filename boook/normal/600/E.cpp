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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , big[MAX] , sum[MAX];
map<int , int> cc[MAX];
vector<int> v[MAX];
void DFS(int now , int fa){
	cc[now][x[now]] = 1;
	big[now] = 1;
	sum[now] = x[now];
	for(auto to : v[now]) if(to != fa){
		DFS(to , now);
		if(cc[to].size() > cc[now].size()){
			swap(cc[now] , cc[to]);
			big[now] = big[to];
			sum[now] = sum[to];
		}
		for(auto ii : cc[to]){
			cc[now][ii.A] += ii.B;
			int tmp = cc[now][ii.A];
			if(tmp > big[now]){
				big[now] = tmp;
				sum[now] = ii.A;
			}
			else if(tmp == big[now]){
				sum[now] += ii.A;
			}
		}
	}
}
int32_t main(){
	IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 2 , n + 1){
    	int a , b;
    	cin >> a >> b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    DFS(1 , 0);
    REP(i , 1 , n + 1) cout << sum[i] << " "; cout << endl;
    return 0;
}