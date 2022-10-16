//  228

#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define ld long double
#define lb lower_bound
#define up upper_bound
#define both equal_range
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define sq(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mp make_pair.
#define ll_MAX 1e15
#define F first
#define S second
typedef vector<int> vi ;
typedef vector<long long> vl ;
typedef pair<int, int> pi ;
#define INF 1011111111
#define EPS (ld)1e-14
#define mod 1000000007
#define PI 3.14159265358979
#define setpr setprecision
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()
void read(int &number) 
{ 
	bool negative = false; 
	register int c; 
 
	number = 0; 
 
	c = getchar(); 
	if (c=='-') 
	{ 
		negative = true; 
		c = getchar(); 
	} 
	for (; (c>47 && c<58); c=getchar()) 
		number = number *10 + c - 48; 
	if (negative) 
		number *= -1; 
} 
long long compute_hash(string const& s) {
    const int p = 31;   
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t ;
    map<ll, int> m ;
    unordered_set<ll> q ;
    while(t--)
    {
      string s ;
      cin >> s ;
      ll h = compute_hash(s) ;
      if(q.empty() || !q.count(h))
      {
          q.insert(h) ;
          cout << "OK" << endl ;
          continue ;
      }
      if(!m.count(h))
      {
          s += "1" ;
          cout << s << endl ;
          m[h] = 2 ;
          continue ;
      }
      string s1 = to_string(m[h]) ;
      s+= s1 ;
      cout << s << endl ;
      m[h]++ ;
    }
    
    return 0 ;
}