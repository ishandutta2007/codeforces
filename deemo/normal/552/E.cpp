#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
string s;

int main(){
    cin >> s;
    s = "1*" + s;
    if (s.size() == 1){
	 cout << (s[0] - 48)	<< endl;
	 return  0;
    }
    ll a = 1 , b = 1;
    ll maxi = -1;
    for (ll i = 1 ; i < s.size() ; i += 2){
	 if (s[i] == '*')	continue;
	 if (s[i] != s.size() - 2 && s[i+2] == '+')  continue;


	 ll mul2 = 1;
	 b = i + 2;
	 for (ll j = b + 1 ; j < s.size() && s[j - 1] == '*'; j += 2)
	     mul2 *= (s[j] - 48);

	 a = b = i;
	 ll sum = 0 , sum2 = 0;
	 int f = 0;
	 
	 while (a > 0){
	     a -= 2;
	     f++;
	     ll m = 1;
	     while (a > 0 && s[a] == '+'){
		  sum += (s[a + 1] - 48);
		  a -= 2;
	     }
	     sum2 = sum + (s[b + 1] - 48) + (s[a + 1] - 48);
	     sum2 *= mul2;
	     int ta = a;
	     while (a > 0 && s[a] == '*'){
		  m *= (s[a + 1] - 48);
		  if (ta != a)    sum2 *= (s[a + 1] - 48);
		  a -= 2;
	     }
	     m *= (s[a + 1] - 48);	     
	     if (ta != a)	sum2 *= (s[a + 1] - 48);
	     sum += m;

	     ll c = ll(sum2 - ll(sum + ll(mul2 * (s[b + 1] - 48))));
	     if (maxi < c)	maxi = c;
	 }     
    }
    if (maxi == -1) maxi = 0;
    
    ll sum = 0;
    for (ll i = 0 ; i < s.size() ;){
	 ll g = (s[i] - 48);
	 i += 2;
	 if (i >= s.size()){
	     sum += g;
	     break;
	 }
	 while (i < s.size() && s[i - 1] == '*'){
	     g *= (s[i] - 48);
	     i += 2;
	 }
	 sum += g;
    }
    sum += maxi;
    cout << sum << endl;
    return 0;
}