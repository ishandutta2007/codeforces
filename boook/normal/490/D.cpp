#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

PII a , b;
int two[2] , three[2] , tmp;
PII F(int now){
	PII ans = mp(0 , 0);
	while(now % 2 == 0) ans.A ++ , now /= 2;
	while(now % 3 == 0) ans.B ++ , now /= 3;
	tmp = now;
	return ans;
}
int32_t main(){
	cin >> a.A >> a.B;
	cin >> b.A >> b.B;
	int vala = 1 , valb = 1;
	PII q;
	q = F(a.A) ; two[0] += q.A , three[0] += q.B , vala *= tmp;
	q = F(a.B) ; two[0] += q.A , three[0] += q.B , vala *= tmp;

	q = F(b.A) ; two[1] += q.A , three[1] += q.B , valb *= tmp;
	q = F(b.B) ; two[1] += q.A , three[1] += q.B , valb *= tmp;
	// DBGG(vala , valb);
	if(vala != valb) cout << "-1" << endl;
	else {
		int step3 = 0;
		int step2 = 0 , sum = 0;
		step3 = abs(three[0] - three[1]);
		sum += step3;
		// DBGG("step3 = " , step3);
		if(three[0] > three[1]){
			two[0] += step3;
			while(step3 --){
				if(a.A % 3 == 0) a.A /= 3 , a.A *= 2;
				else a.B /= 3 , a.B *= 2;
			}
		}
		else{
			two[1] += step3;
			while(step3 --){
				if(b.A % 3 == 0) b.A /= 3 , b.A *= 2;
				else b.B /= 3 , b.B *= 2;
			}
		}


		step2 = abs(two[0] - two[1]);
		sum += step2;
		if(two[0] > two[1]){
			while(step2 --){
				if(a.A % 2 == 0) a.A /= 2;
				else a.B /= 2;
			}
		}
		else {
			while(step2 --){
				if(b.A % 2 == 0) b.A /= 2;
				else b.B /= 2;
			}
		}
		cout << sum << endl;
		cout << a.A << " " << a.B << endl;
		cout << b.A << " " << b.B << endl;


	}
    return 0;
}