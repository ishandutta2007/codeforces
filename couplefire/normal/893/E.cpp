#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000100ll
#define MAXM 25ll
#define MOD 1000000007ll

long long spf[MAXN];
long long ncr[MAXN][MAXM];
long long pow2[MAXN];

void sieve() 
{ 
    spf[1] = 1; 
    for (long long i=2; i<MAXN; i++) 
        spf[i] = i;

    for (long long i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (long long i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (long long j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
vector<long long> getFact(long long x) { 
    vector<long long> ret; 
    while (x != 1) { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int main(){
    //freopen("a.in", "r", stdin);
    pow2[0] = 1;
    for(long long i = 1; i<MAXN; i++){
        pow2[i] = (pow2[i-1]*2)%MOD;
    }
    ncr[0][0] = 0;
    for(long long i = 1; i<MAXN; i++){
        for(long long j = 0; j<min(MAXM, i+1); j++){
            if(j == 0 || i == j){
                ncr[i][j] = 1;
                continue;
            }
            ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%MOD;
        }
    }
    sieve();
    long long t; cin >> t;
    while(t--){
        long long a, b; cin >> a >> b;
        vector<long long> re = getFact(a);
        map<long long, long long> mp;
        for(auto i : re){
            //cout << i << endl;
            mp[i]++;
        }
        long long ans = 1;
        for(auto i : mp){
            ans *= ncr[i.second+b-1][i.second];
            //cout << ncr[i.second+b-1][i.second] << endl;
            ans %= MOD;
        }
        ans *= pow2[b-1];
        ans %= MOD;
        cout << ans << endl;
        //cout << endl;
    }
}