#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	string x;
    int a;
    cin >> x >> a;
    a %= 1440;
    int a1 = 10*int(x[0]-'0')+int(x[1]-'0');
    int a2 = 10*int(x[3]-'0')+int(x[4]-'0');
    if (a2+(a % 60) >= 60) a1++;
    a2 = (a2+a) % 60;
    a /= 60;
    a1 =(a1+a) % 24;
    if (a1 < 10) cout << 0;
    cout << a1 << ':';
    if (a2<10) cout << 0;
    cout << a2;
	return 0;
}