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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , k , pre[MAX] , sp[MAX][20];
string s[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> s[i];
    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + s[i].size();
    int rpo = 0;
    sp[n + 1][0] = n + 1;
    REP(i , 1 , n + 1){
    	while(rpo + 1 <= n && pre[rpo + 1] - pre[i - 1] + rpo + 1 - i <= k) rpo ++;
    	sp[i][0] = rpo + 1;
    }
    // cout << "get to = ";
    // REP(i , 1 , n + 1) cout << sp[i][0] << " " ; cout << endl;
    REP(j , 1 , 20){
    	REP(i , 1 , n + 2){
    		sp[i][j] = sp[sp[i][j - 1]][j - 1];
    	}
    }
    int ans = 0 , id;
    REP(i , 1 , n + 1){
    	int tmp = m , res = i;
    	RREP(j , 19 , 0){
    		if(tmp >= (1 << j)){
    			tmp -= (1 << j);
    			res = sp[res][j];
    		}
    	}
    	if(res - i > ans){
    		ans = res - i;
    		id = i;
    	}
    }
    ans = id + ans - 1;
    while(id <= ans){
    	REP(i , id , sp[id][0]){
    		if(i != id) cout << " ";
    		cout << s[i];
    	}
    	id = sp[id][0];
    	cout << endl;
    }
    return 0;
}