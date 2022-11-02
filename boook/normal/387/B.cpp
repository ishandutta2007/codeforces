#include <bits/stdc++.h>
using namespace std;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 3010
#define INF 0x3f3f3f3f

int n , m;
int a[MAX] , b[MAX];
VI tmp;
map<int , int> cc;
int32_t main(){
	cin >> n >> m;
	REP(i , n) cin >> a[i];
	REP(i , m) cin >> b[i] , cc[b[i]] ++;
	sort(a , a + n , greater<int>());
	int ans = 0;
	REP(i , n){
		if(cc.find(a[i]) == cc.end() || cc[a[i]] == 0){
			tmp.pb(a[i]);
			// DBGG("46" , a[i]);
		}
		else cc[a[i]] --;
	}
	priority_queue<int> pq;
	for(auto i : cc){
		while(i.B --) pq.push(i.A);
	}
	for(auto now : tmp){
		if(pq.size() && pq.top() > now) pq.pop();
		else ans++;
	}
	cout << ans << endl;
    return 0;
}