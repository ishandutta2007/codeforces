/*
    God save us everyone 
    will we burn inside the fires of a thousand suns?
    for the sins of our hands 
    the sins of our tongues
    the sins of our fathers
    the sins of our young..
*/

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
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

ll n;
const ll max_n = 4 * 1e3 + 10;
const ll q = 1e9 + 7;
ll d[4010][4010] , dp[max_n] , sdp[max_n];

int main(){
    cin >> n;
    if (n == 1){
	 cout << 1 << endl;
	 return  0;
    }
    d[0][0] = 1;
    for (ll i = 1 ; i < 4009 ; i++){
	 d[i][0] = d[i][i] = 1;
	 for (ll j = 1 ; j < i ; j++)
	     d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % q;
    }

    sdp[0] = 1;
    sdp[1] = 2;
    for (ll i = 2 ; i < max_n ; i++){
	 sdp[i] = sdp[i - 1];
	 for (ll j = 0 ; j <= i - 1 ; j++){
	     ll t = d[i - 1][j];
	     t *= sdp[i - j - 1];
	     sdp[i] = (sdp[i] + t) % q;
	 }
    }

    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2 ; i < max_n ; i++){
	 for (ll j = 0 ; j <= i - 1 ; j++){
	     ll t = d[i - 1][j];
	     t *= dp[i - j - 1];
	     dp[i] = (dp[i] + t) % q;
	 }
    }

    cout << (sdp[n] + q - dp[n]) % q << endl;

    return 0;
}