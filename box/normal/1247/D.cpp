#include <bits/stdc++.h>
using namespace std;

map<int, int> mem;
vector<int> co;

int k;
long long ovc;

void complementandcache(int v) {
    int orig = 1;
    long long comp = 1;
    bool compFlood = false;
    for(int i=2; i*i <= v; i++) {
        if(v % i == 0) {
            int cnt = 0;
            while(v % i == 0) {
                cnt++;
                v /= i;
            }
            cnt %= k;
            for(int t=0; t<cnt; t++) orig *= i;
            if(compFlood) continue;
            if(cnt == 0) continue;
            for(int t=0; t<(k-cnt); t++) {
                comp *= i;
                if(comp < 0 || comp >= 1000000) { compFlood = true; break; }
            }
        }
    }
    if(v != 1) {
        orig *= v;
        if(!compFlood) {
            for(int i=0; i<k-1; i++) {
                comp *= v;
                if(comp < 0 || comp >= 1000000) { compFlood = true; break; }
            }
        }
        // one single prime power
    }
    mem[orig]++;
    if(comp == orig) ovc++;
    if(!compFlood) co.push_back(comp);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long tot = 0;
    int n; cin >> n >> k;
    while(n--) {
        int v; cin >> v;
        complementandcache(v);
    }
    for(int i:co) {
        tot += mem[i];
    }
    cout << (tot-ovc)/2 << endl;
}