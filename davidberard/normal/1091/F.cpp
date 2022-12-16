#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 100100;

ll n;

ll gamt = 0;
ll t = 0;
bool seenW = 0;
ll water = 0;
ll grass = 0;
ll health = 0;

ll a[NMAX]; // length
char s[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    cin >> s;
    for(int i=0; i<n; ++i) {
        if(s[i] == 'G') {
            grass += a[i]*2;
            t += a[i];
            health -= a[i];
        } else if(s[i] == 'W') {
            water += a[i]*2;
            t += a[i];
            health -= a[i];
            seenW = true;
        } else if(s[i] == 'L') {
            health -= a[i];
            t += a[i];
        }
        
        while(health < 0) {
            if(seenW && water) {
                ll diff = min(-health, water);
                water -= diff;
                health += diff;
                t += diff;
            } else if(grass) {
                ll diff = min(-health, grass);
                grass -= diff;
                health += diff;
                t += 2*diff;
            } else if(seenW) {
                t += -3*health;
                health = 0;
            } else {
                t += -5*health;
                health = 0;
            }
        }
    }
    cout << t << endl;
    return 0;
}