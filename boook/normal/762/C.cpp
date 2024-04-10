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
#define MAX 100900
#define INF 0x3f3f3f3f

string a , b;
int pos , fr[MAX] , ba[MAX];
int32_t main(){
	IOS;
    cin >> a >> b;
    int ans = b.size() , v1 = 0 , v2 = b.size() - 1;
    pos = 0;
    REP(i , 0 , b.size()){
    	while(pos < a.size() && b[i] != a[pos]) pos ++;
    	fr[i] = pos;
    	pos = min(pos + 1 , (int)a.size());
    }
    pos = a.size() - 1;
    RREP(i , b.size() - 1 , 0){
    	while(pos >= 0 && b[i] != a[pos]) pos --;
    	ba[i] = pos;
    	pos = max(pos - 1 , -1);
    }
    
    // REP(i , 0 , b.size()) cout << fr[i] << " "; cout << endl;
    // REP(i , 0 , b.size()) cout << ba[i] << " "; cout << endl;
    ba[b.size()] = a.size();
    int lpo = -1 , rpo = 0;
    REP(i , 0 , a.size() + 1){
    	while(lpo + 1 < b.size() && fr[lpo + 1] < i) lpo ++;
    	while(rpo < b.size() && ba[rpo] < i) rpo ++;
    	// cout << fr[lpo] << " " << ba[rpo] << " "; DB4("lpo = " , lpo , "rpo = " , rpo);
    	if(lpo + 1 > rpo - 1) return cout << b << endl , 0;
    	else if(lpo + 1 <= rpo - 1){
    		if((rpo - 1) - (lpo + 1) + 1 < ans){
    			ans = (rpo - 1) - (lpo + 1) + 1;
    			v1 = lpo + 1;
    			v2 = rpo - 1;
    		}
    	}
    }
    // DB4("v1 = " , v1 , "v2 = " , v2);
    if(ans == b.size()) return cout << "-" << endl , 0;
    REP(i , 0 , b.size()){
    	if(v1 <= i && i <= v2);
    	else cout << b[i] ;
    }cout << endl;
    return 0;
}