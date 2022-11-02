/*input
1.5 1.7 2.5
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
#define MAX 
#define INF 0x3f3f3f3f

string s[] = {"x^y^z" , "x^z^y" , "(x^y)^z" , "(x^z)^y" , "y^x^z" , "y^z^x" , 
			  "(y^x)^z" , "(y^z)^x" , "z^x^y" , "z^y^x" , "(z^x)^y" , "(z^y)^x"};
long double F(long double a , long double b , long double c){
	long double res = pow(b , c) * log(a);
	return res;
}
long double G(long double a , long double b , long double c){
	long double res = b * c * log(a);
	return res;
}
long double x , y , z;
int32_t main(){
	cin >> x >> y >> z;
	long double val = -1e100;
	string ans;
	if(F(x , y , z) > val) val = F(x , y , z) , ans = s[0];
	if(F(x , z , y) > val) val = F(x , z , y) , ans = s[1];
	if(G(x , y , z) > val) val = G(x , y , z) , ans = s[2];
	if(F(y , x , z) > val) val = F(y , x , z) , ans = s[4];
	if(F(y , z , x) > val) val = F(y , z , x) , ans = s[5];
	if(G(y , x , z) > val) val = G(y , x , z) , ans = s[6];
	if(F(z , x , y) > val) val = F(z , x , y) , ans = s[8];
	if(F(z , y , x) > val) val = F(z , y , x) , ans = s[9];
	if(G(z , x , y) > val) val = G(z , x , y) , ans = s[10];
	cout << ans << endl;
    return 0;
}