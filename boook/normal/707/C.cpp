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
#define int long long
#define INF 0x3f3f3f3f

int n , a , b , c;

int32_t main(){
	IOS;    
	cin >> n;
	if(n == 1 || n == 2){
		cout << -1 << endl;
		return 0;
	}
	else if(n == (1 << __lg(n))){
		cout << 3 * n / 4 << " " << 5 * n / 4 << endl;
	}
	else {
		int val = n , base = 0;
		while(val % 2 == 0) val /= 2 , base ++;
		int tmp = val * val / 2;
		a = tmp , b = tmp + 1 , c = val;
		a *= (1 << base);
		b *= (1 << base);
		c *= (1 << base);
		if(n != a) cout << a << " ";
		if(n != b) cout << b << " ";
		if(n != c) cout << c << " ";
		cout << endl;
	}
    return 0;
}