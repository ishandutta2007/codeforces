/*input
2
1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define IOS cin.tie() , cout.sync_with_stdio(0)
///----------------------------
#define MAX 300000
int n , x[MAX] , pre[MAX];
int main(){
	IOS , cin >> n; n ++;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) if(x[i] > 1 && x[i - 1] > 1){
		cout << "ambiguous" << endl;
		int sum = 0;
		REP(ii , 1 , n + 1) sum += x[ii];
		REP(ii , 1 , n + 1) pre[ii] = pre[ii - 1] + x[ii];
		vector<int> a , b;
		REP(ii , 1 , n + 1){
			REP(jj , 1 , x[ii] + 1){
				a.pb(pre[ii - 1]);
				b.pb(pre[ii - 1]);
			}
		}
		b[pre[i] - 1] = pre[i - 2] + 1;
		for(auto to : a) cout << to << " " ;cout << endl;
		for(auto to : b) cout << to << " " ;cout << endl;
		return 0;
	}
	cout << "perfect" << endl;
	return 0;
}