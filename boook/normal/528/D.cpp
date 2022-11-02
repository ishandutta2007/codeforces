/*input
40 20 40
ACATACATACATACATACATACATACATACATACATACAT
ACATACATACATACATACAT
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
#define MAX 800000
#define INF 0x3f3f3f3f
#define cplx pair<double , double>

const double PI = acos(-1);
cplx operator + (const cplx a , const cplx b){ return mp(a.A + b.A , a.B + b.B); }
cplx operator - (const cplx a , const cplx b){ return mp(a.A - b.A , a.B - b.B); }
cplx operator * (const cplx a , const cplx b){ 
	return mp(a.A * b.A - a.B * b.B , a.B * b.A + a.A * b.B); }

cplx tmp[MAX] , w[MAX];
void FFT(cplx now[MAX] , int n , int base){
	int siz = 1 , pat = n / 2 - 1;
	RREP(i , base - 1 , 0){
		REP(j , 0 , n){
			int fr = (j >> i) , ba = (j & pat);
			int a = ((fr % siz) * 2 + 0) << i | ba;
			int b = ((fr % siz) * 2 + 1) << i | ba;
			tmp[j] = now[a] + w[fr << i] * now[b];
		}
		REP(j , 0 , n) now[j] = tmp[j];
		siz <<= 1 , pat >>= 1;
	}
}
void IFFT(cplx now[MAX] , int n , int base){
	FFT(now , n , base);
	reverse(now + 1 , now + n);
	REP(i , 0 , n) now[i].A = now[i].A / n;
}
cplx a[MAX] , b[MAX];

int n , m , k , ok[MAX] , nn , base , pre[MAX];

string s1 , s2;
void solveinit(){
	nn = (1 << 19) , base = 19;
	REP(i , 0 , nn){
		w[i].A = cos(PI * 2 * i / nn);
		w[i].B = sin(PI * 2 * i / nn);
	}
}
void solve(char now){
	// DBGG("now solve = " , now);
	REP(i , 0 , nn) a[i] = b[i] = mp(0 , 0);

	REP(i , 0 , n) pre[i] = s1[i] == now;
	REP(i , 1 , n) pre[i] += pre[i - 1];
	REP(i , 0 , n){
		int l = (i - k > 0) ? pre[i - k - 1] : 0;
		int r = (i + k < n) ? pre[i + k] : pre[n - 1];
		int sum = r - l;
		if(sum != 0) a[i].A = 1;
	}
	REP(i , 0 , m){
		if(s2[i] == now) b[i].A = 1;
	}
	// REP(i , 0 , n) cout << b[i].A << " " ; cout << endl;

	FFT(a , nn , base);
	FFT(b , nn , base);
	
	// REP(i , 0 , n) cout << a[i].A << " " ; cout << endl;
	REP(i , 0 , nn) a[i] = a[i] * b[i];
	IFFT(a , nn , base);
	
	// REP(i , 0 , n + m) cout << round(a[i].A) << " " ; cout << endl;
	REP(i , 0 , n){
		ok[i] += round(a[i + m - 1].A);
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	cin >> s1 >> s2;
	reverse(ALL(s2));

	solveinit();
	solve('A');
	solve('T');
	solve('C');
	solve('G');

	int ans = 0;
	REP(i , 0 , n) if(ok[i] == m) ans ++;
	cout << ans << endl;
    return 0;
}