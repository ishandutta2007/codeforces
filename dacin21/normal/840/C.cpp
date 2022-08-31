#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

const ll mod = ll(1e9)+7;

bool issq(ll x){
    if(x<=0) return x==0;
    ll i=1, j=1e10;
    while(j>0){
        while(x/(i+j)>=i+j) i+=j;

        j/=2;
    }
    return x/i==i && (x-1)/i!=i;
}
ll inv(ll x){
    int e = mod-2;
    ll a=1;
    for(int i=1<<30;i;i>>=1){
        a=(a*a)%mod;
        if(e&i) a = a*x%mod;
    }
    assert(a*x%mod == 1);
    return a;
}
vector<ll> fact, ifact;
vector<vector<ll> > destc;
ll destmul(int has, int todest){
    return destc[has][todest];
}
vector<vector<ll> > contc;
ll ncr(ll n, ll k){
    return contc[n][k];
}
ll contmul(int has, int tocont){
    return ncr(has, tocont) * fact[tocont]%mod;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int lim = 400;
    fact.assign(2*lim, 1);
    ifact.assign(2*lim, 1);
    for(int i=1;i<2*lim;++i) fact[i] = fact[i-1]*i%mod;
    ifact[2*lim-1] = inv(fact[2*lim-1]);
    for(int i=2*lim-1;i>0;--i) ifact[i-1] = ifact[i]*i%mod;
    destc.assign(lim, vector<ll>(lim, 0));
    contc.assign(lim, vector<ll>(lim, 0));
    for(int i=0;i<lim;++i){
        contc[0][i] = (i==0);
        contc[1][i] = (i<2);
        destc[i][0] = 1;
    }
    for(int i=2;i<lim;++i){
        contc[i][0] = 1;
        for(int j=1;j<lim;++j){
            contc[i][j] = contc[i-1][j] + contc[i-1][j-1];
            if(contc[i][j]>mod) contc[i][j]-=mod;
            destc[i][j] = destc[i-2][j-1] * (i * (i-2)/4) % mod;
        }
    }
    for(int i=0;i<lim;++i){
        for(int j=0;j<lim;++j){
            //destc[i][j] = destc[i][j] * ifact[j] % mod;
        }
    }


    int n; cin >> n;
    vector<pair<ll, int> > c;
    for(int i=0;i<n;++i){
        ll a;
        cin >> a;
        bool d = false;
        for(auto &e:c){
            if(issq(e.first*a)){
                d=true;
                ++e.second;
                break;
            }
        }
        if(!d){
            c.emplace_back(a, 1);
        }
    }
    int maxc = n+1+2;
    vector<ll> DP(maxc, 0);
    DP[0] = 1;
    for(int i=0;i<(int)c.size();++i){
        int lim = c[i].second;
        if(!lim) continue;
        vector<ll> DP2(maxc, 0);

        for(int j=0;j<maxc;++j){
            for(int cr=0;cr<=lim && j+2*cr<maxc;++cr){
                for(int dest=0;dest<=lim-cr && 2*dest<=j;++dest){
                    int cont = lim-cr-dest;
                    ll mul = destmul(j, dest) * contmul(j-2*dest, cont) %mod;
                    //cerr << j << " " << cr << " " << dest << " " << cont << " : " << mul << "\n";
                    mul = mul*ncr(lim, cr)%mod * ncr(lim-cr, dest)%mod;
                    //cerr << j << " " << cr << " " << dest << " " << cont << " : " << mul << "\n";
                    DP2[j+2*cr-2*dest] = (DP2[j+2*cr-2*dest]+DP[j]*mul)%mod;
                }
            }
        }
        DP.swap(DP2);
    }
    ll ans = (DP[2])%mod;
    cout << ans << "\n";




    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}