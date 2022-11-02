/*input
4 3 2
1 2 3 2
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX (1 << 18) + 10
#define INF 0x3f3f3f3f
#define mod 1009
#define cplx complex<double> 
const double PI = acos(-1);

vector<int> v[MAX];
cplx tmp[MAX] , x[MAX] , y[MAX] , w[MAX] , I(0 , 1);
int nn , base , maxn = (1 << 18);
void FFT(cplx now[MAX]){
	int siz = 0 , pat = (nn >> 1) - 1 , mul = 18 - base;
	RREP(i , base - 1 , 0){
		REP(j , 0 , nn){
			int fr = j >> i , ba = j & pat;
			int a = ((fr & siz) << 1 | 0) << i | ba;
			int b = ((fr & siz) << 1 | 1) << i | ba;
			tmp[j] = now[a] + now[b] * w[fr << i << mul];
		}
		REP(j , 0 , nn) now[j] = tmp[j];
		siz = (siz << 1 | 1) , pat >>= 1;
	}
}
void IFFT(cplx now[MAX]){
	FFT(now) , reverse(now + 1 , now + nn);
	REP(i , 0 , nn) now[i] /= nn;
}
void solve(int a , int b){
	base = 0;
	while((1 << base) < v[a].size() + v[b].size()) base ++ , nn = (1 << base);

	REP(i , 0 , nn){
		x[i] = i < v[a].size() ? cplx(v[a][i] , 0) : cplx(0 , 0);
		y[i] = i < v[b].size() ? cplx(v[b][i] , 0) : cplx(0 , 0);
	}
	FFT(x) , FFT(y);
	REP(i , 0 , nn) x[i] = x[i] * y[i];
	IFFT(x);

	v[a].clear();
	REP(i , 0 , nn) v[a].pb((long long)(x[i].real() + 0.5) % mod);
	while(v[a].back() == 0) v[a].pop_back();
}

int n , m , k , a[MAX] , cnt[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> a[i] , cnt[a[i]] ++;
	REP(i , 1 , m + 1) v[i].resize(cnt[i] + 1 , 1);

	REP(i , 0 , maxn) w[i] = exp(2 * PI * i / maxn * I);
	priority_queue<PII , vector<PII> , greater<PII>> pq;
	REP(i , 1 , m + 1) pq.push(mp(v[i].size() , i));
	while(pq.size() > 1){
		PII a = pq.top(); pq.pop();
		PII b = pq.top(); pq.pop();
		solve(a.B , b.B);
		pq.push(mp(v[a.B].size() , a.B));
	}
	cout << v[pq.top().B][k] << endl;
    return 0;
}