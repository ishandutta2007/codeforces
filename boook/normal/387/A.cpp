#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define MAX 
#define INF 0x3f3f3f3f

string a , b;
int T(char now){
	return now - '0';
}
int32_t main(){
	cin >> a >> b;
	int q = T(a[0]) * 10 + T(a[1]) , w = T(a[3]) * 10 + T(a[4]);
	int e = T(b[0]) * 10 + T(b[1]) , r = T(b[3]) * 10 + T(b[4]);
	int tma = q * 60 + w;
	int tmb = e * 60 + r;
	int tmp = tma - tmb;
	if(tmp < 0) tmp += 24 * 60;
	printf("%02d:%02d\n", tmp / 60 , tmp % 60);
    return 0;
}