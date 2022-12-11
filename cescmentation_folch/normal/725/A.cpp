#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int n;
    cin >> n >> a;
    int res = 0;
    int i = 0;
    while(i < n and a[i] == '<') {
        ++res;
        ++i;
    }
    i = n -1;
    while (i >= 0 and a[i] == '>') {
        ++res;
        --i;
    }
    cout << res << '\n';
}