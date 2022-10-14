// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int solve(ll& a, ll& b, ll& c) {
    if(a < b) { swap(a, b); } if(b < c) { swap(b, c); } if(a < b) { swap(a, b); } 
    if(b + c == 0) return 0;
    if(a - c <= 1) return ((ll)a+b+c)/3;
    int p1 = min((a-b)/3, min(a/4, c)); a -= 4 * p1; b -= p1; c -= p1;
    int p2 = 0;
    if(a - b <= 1 && (b-c)/3)  { p2 = (b-c)/3; a -= 3*p2; b -= 3*p2; } 
    else if(a - c <= 2) { p2 = c/3; a -= 2*p2; b -= 2*p2; c -= 2*p2; }
    int p3 = min(min(min(a/2, a-b), min(b-c, (a-c)/2)), min(a/2-1, b-1))+1; a -= 2 * p3; b -= p3;
    return 2*p1+2*p2+p3+solve(a,b,c);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll a, b, c; cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}