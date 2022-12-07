#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007

struct Color {
    long long id;
    long long val;
    long long color;
};

bool sort_val(Color a, Color b) {
    return a.val < b.val;
}
bool sort_id(Color a, Color b) {
    return a.id < b.id;
}

long long n, k;
long long g; // How many of each colour is needed.
// m --> How many of each value is present. 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    long long t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n >> k;
    Color c[n+5];
    map <long long, long long> m;
    forn(i, n+5) m[i] = 0; 
    g = 0;
    forn(i, n) {
        cin >> c[i].val;
        c[i].id = i;
        c[i].color = -1;
        m[c[i].val] += 1;
    }
    for(auto i : m) {
        g += min(k, i.second);
    }
    g = (g/k);
    sort(c, c+n, sort_val);
    // forn(i, n) cout << c[i].val << " " << c[i].id << "\n";
    long long t1 = 1; // t1 will be what colour we want to palong long the current value.
    t1 %= k;
    long long t2 = 1; // x will be the number of times current value has come up.
    c[0].color = 0;
    for(long long i=1; i<n; i++) {
        if(c[i].val==c[i-1].val) {
            if(t2 < k) {
                c[i].color = t1;
                t1 += 1;
                t1 %= k;
                t2 += 1;
            }
        }
        else {
            c[i].color = t1;
            t1 += 1;
            t1 %= k;
            t2 = 1;
        }
    }
    // forn(i, n) cout << c[i].val << " " << c[i].id << " " << c[i].color << "\n";
    g *= k; // represents the total palong longed now.
    long long t3 = 0; // t3 cannot be greater than g
    forn(i, n) {
        if(c[i].color!=-1) {
            if(t3>=g) c[i].color = -1;
            t3 += 1;
        }
    }
    sort(c, c+n, sort_id);
    forn(i, n) 
        cout << c[i].color + 1 << " ";
        
    cout << endl;
}
    return 0;
}