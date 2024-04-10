#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;



const int nax = 5005, inf = 1e9 + 1, mod = 998244353;

int n;
string a;
vector <int> opt;


string sum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string best ;

bool better(string x) {
	for(int i = 0; i < ss(x); ++i) {
		if(x[i] != best[i])
			return x[i] < best[i];
	}
	return 1;
}
string s;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	
	FOR(i, n + 1)
		best.pb('9');
	
	cin >> s;
	
	int mid = n / 2;
	if(s[mid] != '0' && mid > 0) {
		opt.pb(mid);
	}
	mid--;
	while(mid >= 0 && s[mid] == '0') {
		mid--;
	}
	if(mid > 0) {
		opt.pb(mid);
	}
	mid = n / 2 +  1;
	while(mid < n && s[mid] == '0') {
		++mid;
	}
	if(mid > 0 && mid < n) {
		opt.pb(mid);
	}
	
	for(auto it: opt) {
		string a = s.substr(0, it);
		string b = s.substr(it, n - it);
		string c = sum(a, b);
		if(ss(c) < ss(best) || (ss(c) == ss(best) && better(c))) {
			best = c;
		}
	}
	cout << best;
	
				
			
	
	
				
	
	
    return 0;
}