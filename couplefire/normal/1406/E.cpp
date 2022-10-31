#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define BLOCK 100

int lp[MAXN+1];
vector<int> primes;

void genPrimes(){
    for(int i=2; i<=MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=MAXN; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

int n;
int check[MAXN];
int _tot = 0;

int op1(int a){
    cout << "A " << a << endl;
    int res; cin >> res;
    return res;
}

int op2(int a){
    cout << "B " << a << endl;
    int res; cin >> res;
    return res;
}

void printans(int a){
    cout << "C " << a << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n == 1){
        printans(1);
        exit(0);
    }
    genPrimes();
    while(primes.back() > n) primes.pop_back();
    primes.insert(primes.begin(), -1);
    vector<int> cur; _tot = n;
    for(int i = 1; i<(int)primes.size(); i++){
        int p = primes[i];
        int res = op2(p);
        int _res = 0;
        for(int j = 1; j*p <=n; j++){
            _res += (!check[p*j]);
            check[p*j] = 1;
        }
        _tot -= _res;
        bool f = false;
        if(_res != res) cur.push_back(p), f = ((int)cur.size() == 1);
        if((cur.empty() && (i == (int)primes.size()-1 || i%BLOCK == 0))||f){
            int tot = op1(1);
            if(tot == _tot) continue;
            int pi = (i-1)/BLOCK*BLOCK+1;
            for(int j = pi; j<=i; j++){
                int tmp = op1(primes[j]);
                if(tmp){
                    cur.push_back(primes[j]);
                    break;
                }
            }
        }
    }
    int ans = 1;
    for(auto p : cur){
        long long tmp = p;
        while(tmp <= 1ll*n && op1((int)tmp)) ans *= p, tmp *= p;
    }
    printans(ans);
}