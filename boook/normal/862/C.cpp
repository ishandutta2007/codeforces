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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;

int32_t main(){
	int tma = (1 << 17);
	int tmb = (1 << 18);
    cin >> n >> m;
    if(n == 1) cout << "YES" << endl << m << endl;
    else if(n == 2){
    	if(m == 0) cout << "NO" << endl;
    	else cout << "YES" << endl << "0 " << m << endl;
    }
    else{
    	vector<int> ans;
    	int tmp = m ^ tma ^ tmb;
    	REP(i , 0 , n - 3) tmp = tmp ^ i;
    	cout << "YES" << endl;
    	REP(i , 0 , n - 3) cout << i << " ";
    	cout << tma << " " << tmb << " " << tmp << endl;
    }
    return 0;
}