/*input
1
100 24 256
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
#define pb   emplcae_bcak
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int t , a , b , c , cnt[MAX];
int C2(int now){ return now * (now - 1) / 2; }
int C3(int now){ return now * (now - 1) * (now - 2) / 6; }
int T(int now){ return now * now - C2(now); }
int H(int now){ return C3(now) + C2(now) * 2 + now; }
int solve(int x , int y , int z){
	if(x == y && x == z) return H(x);
	else if(x == y) return T(x) * z;
	else if(x == z) return T(x) * y;
	else if(y == z) return T(y) * x;
	else return x * y * z;
}
int32_t main(){
	IOS;
	REP(i , 1 , MAX) for(int j = i ; j < MAX ; j += i) cnt[j] ++;
	cin >> t;
	REP(times , 0 , t){
		cin >> a >> b >> c;
		int all = cnt[__gcd(a , __gcd(b , c))];

		int ab = cnt[__gcd(a , b)] - all;
		int bc = cnt[__gcd(b , c)] - all;
		int ca = cnt[__gcd(c , a)] - all;
		int A = cnt[a] - ab - ca - all;
		int B = cnt[b] - ab - bc - all;
		int C = cnt[c] - ca - bc - all;
		int sum = all + ab + bc + ca + A + B + C;

		int ans = 0;
		ans += (cnt[b] * cnt[c] - C2(bc + all)) * A;
		ans += (cnt[c] * (cnt[a] - A) - C2(ca + all)) * B;
		ans += ((cnt[a] - A) * (cnt[b] - B) - C2(ab + all)) * C;
		// DBGG("now ans = " , ans);
		ans += H(all);
		// ans += solve(all , all , all);
		ans += T(all) * ab;
		ans += T(all) * bc;
		ans += T(all) * ca;
		// ans += solve(ab , all , all);
		// ans += solve(all , bc , all);
		// ans += solve(all , all , ca);

		ans += T(ab) * all;
		ans += T(bc) * all;
		ans += T(ca) * all;
		// ans += solve(ab , ab , all);
		// ans += solve(all , bc , bc);
		// ans += solve(ca , all , ca);
		
		ans += all *  ab * ca;
		ans += all *  ab * bc;
		ans += ca  * all * bc;

		// ans += solve(all , ab , ca);
		// ans += solve(all , ab , bc);
		// ans += solve(ca , all , bc);
		
		ans += T(ab) * ca;
		ans += T(ca) * ab;
		// ans += solve(ab , ab , ca);
		// ans += solve(ca , ab , ca);
		
		ans += T(bc) * ab;
		ans += T(ab) * bc;

		// ans += solve(ab , bc , bc);
		// ans += solve(ab , ab , bc);

		ans += T(bc) * ca;
		ans += T(ca) * bc;

		// ans += solve(ca , bc , bc);
		// ans += solve(ca , bc , ca);
		
		ans += ca * ab * bc;
		//solve(ca , ab , bc);
		// ans += solve(ca , ab , bc);
		

		// DB4(all , ab , bc , ca);
		// DB4(A , B , C , " = ");
		// ans += C3(all) - C3(sum - A) - C3(sum - B) - C3(sum - C) + C3(A) + C3(B) + C3(C);

		cout << ans << endl;
	}
    return 0;
}