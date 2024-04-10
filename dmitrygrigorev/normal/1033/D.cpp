#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 3e18;
int pw(int a, int b){
    int res = 1;
    for (int i=0;i<b;i++){
        if (INF / res <= a){
            return INF;
        }
        res *= a;
    }
    return res;

}
bool prime(int kek){
    for (int i=2; i*i <= kek; i++){
        if (kek%i==0) return false;
    }
    return true;
}
pair<int, int> get(int num){
    if (num==1) return {-1, -1};
    for (int root=2; root <= 4; root++){
        int L=1, R = 1e18;
        while (R-L>1){
            int M = (L+R)/2;
            int z = pw(M, root);
            if (z > num) R = M;
            else L = M;
        }
        //cout << num << " " << L << " " << root << endl;
        int kek = pw(L, root);
        if (kek != num) continue;
        if (prime(L)) return {L, root};
    }
    return {-1, -1};
}
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
int MOD = 998244353;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    map<int, int> del;
    vector<int> rl;
    vector<int> prs;
    for (int i=0; i < n; i++){
        pair<int, int> rt = get(a[i]);
        if (rt.first != -1){
            prs.push_back(rt.first);
            //cout << rt.first << " " << rt.second << endl;
            del[rt.first] += rt.second;
            continue;
        }
        else rl.push_back(a[i]);
    }
    vector<int> nl;
    for (int i=0; i < rl.size(); i++){
        bool add = true;
        for (int j=0; j < prs.size(); j++){
            if (rl[i] % prs[j] == 0){
                int A = rl[i] / prs[j], B = prs[j];
                del[A]++, del[B]++;
                add = false;
                break;
            }
        }
        if (add && rl[i] != 1) nl.push_back(rl[i]);
    }
    int ans = 1;
    //cout << nl.size() << endl;
    set<int> primes;
    for (int i=0; i < nl.size(); i++){
        for (int j=i+1; j < nl.size(); j++){
            if (nl[i] == nl[j]) continue;
            int g = gcd(nl[i], nl[j]);
            if (g != 1){
                primes.insert(g);
                primes.insert(nl[i]/g);
                primes.insert(nl[j]/g);
            }
        }
    }
    map<int, int> keke;
    for (int i=0;i<nl.size(); i++){
        for (auto it = primes.begin(); it != primes.end(); it++){
            int K = *it;
            if (nl[i] % K == 0){
                //cout << K << " " << nl[i]/K << " " << nl[i] << endl;
                del[K]++, del[nl[i]/K]++;
                nl[i]=1;
                break;
            }
        }
        if (nl[i] != 1){
            keke[nl[i]]++;
        }
    }
    //cout << ans << endl;
    for (auto it = del.begin(); it != del.end(); it++){
        pair<int, int> p = *it;
        ans *= (p.second+1);
        ans %=MOD;
    }
    for (auto it =keke.begin(); it != keke.end(); it++){
        pair<int, int> p = *it;
        ans *= (p.second+1);
        ans %=MOD;
        ans *= (p.second+1);
        ans %=MOD;
    }
    cout << ans;
}