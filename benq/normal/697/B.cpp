#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    string k,k1; cin >> k;
    int k2 = 0;
    int cur = 1;
    F0R(i,k.length()) {
        if (k[i] == 'e') {
            k1 = k.substr(i+1,k.length()-i-1);
            k = k.substr(0,i);
            break;
        }
    }
    F0R(i,stoi(k1)) {
        cur++;
        if (cur<k.length()) k[cur-1] = k[cur], k[cur] = '.';
        else {
        	k[k.length()-1] = '0';
            k += '.';
        }
    }
    F0R(i,cur-1) {
    	if (k[i] == '0') k = k.substr(1,k.length()-1);
    	else break;
    }
    if (cur == k.length()-2 && k[k.length()-1] == '0') k = k.substr(0,k.length()-2);
    if (k[k.length()-1] == '.') cout << k.substr(0,k.length()-1);
    else cout << k;
}