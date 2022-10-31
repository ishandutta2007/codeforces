#include <bits/stdc++.h>
#include <chrono>
#include <time.h>
 
using namespace std;
 
#define lli long long int
#define mod 1000000007 
#define set(n) cout << fixed << setprecision(n)
#define fi first
#define se second
#define pll pair<lli, lli>
#define mp make_pair
 
const double PI = acos(-1);
 
struct myHash { // collision handling comparator for pair class
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
 
class segTree { // segment tree
    vector<lli> a; // array whose segment tree needs to be built
    vector<lli> tree; // segment tree
    vector<lli> lazy;
    lli sel;
 
    lli minRange(lli left, lli right){
        return min(left, right);
    }
 
    lli maxRange(lli left, lli right){
        return max(left, right);
    }
 
    lli rangeSum(lli left, lli right){
        return left + right;
    }
 
    void build(lli index, lli start, lli end){
        if(start > end){
            return;
        }
        if(start == end){
            tree[index] = a[start];
            return;
        }
        lli mid = (start + end) / 2;
        build(2 * index, start, mid);
        build(2 * index + 1, mid + 1, end);
        lli left = tree[2 * index];
        lli right = tree[2 * index + 1];
        if(sel == 0){
            tree[index] = minRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 1){
            tree[index] = maxRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 2){
            tree[index] = rangeSum(tree[2 * index], tree[2 * index + 1]);
        }
    }
 
    lli query(lli index, lli start, lli end, lli l, lli r){
 
        if(lazy[index] != 0){
            if(sel == 0){
                tree[index] += lazy[index];
            }
            else if(sel == 1){
                tree[index] += lazy[index];
            }
            else if(sel == 2){
                tree[index] += (end - start + 1) * lazy[index];
            }
 
            if(start != end){
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }
 
        if(l > end || r < start){
            if(sel == 0){
                return LLONG_MAX;
            }
            else if(sel == 1){
                return LLONG_MIN;
            }
            else if(sel == 2){
                return 0;
            }
        }
 
        if(start >= l && end <= r){
            return tree[index];
        }
        lli mid = (start + end) / 2;
        lli left = query(2 * index, start, mid, l, r);
        lli right = query(2 * index + 1, mid + 1, end, l, r);
        if(sel == 0){
            return minRange(left, right);
        }
        else if(sel == 1){
            return maxRange(left, right);
        }
        else if(sel == 2){
            return rangeSum(left, right);
        }
    }
 
    void update(lli index, lli start, lli end, lli l, lli r, lli inc){
 
        if(lazy[index] != 0){  // if current index is not computed then compute it
            if(sel == 0){
                tree[index] += lazy[index];
            }
            else if(sel == 1){
                tree[index] += lazy[index];
            }
            else if(sel == 2){
                tree[index] += (r - l + 1) * lazy[index];
            }
 
            if(start != end){
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }
 
        if(l <= start and end <= r){
            if(sel == 0){
                tree[index] += inc;
            }
            else if(sel == 1){
                tree[index] += inc;
            }
            else {
                tree[index] += (end - start + 1) * inc;
            }
            if(start != end){
                lazy[2 * index] += inc;
                lazy[2 * index + 1] += inc;
            }
            return;
        }
 
        if(r < start || l > end){
            return;
        }
        if(start == end){
            tree[index] += inc;
            return;
        }
        lli mid = (start + end) / 2;
        update(2 * index, start, mid, l, r, inc);
        update(2 * index + 1, mid + 1, end, l, r, inc); 
        if(sel == 0){
            tree[index] = minRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 1){
            tree[index] = maxRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 2){
            tree[index] = rangeSum(tree[2 * index], tree[2 * index + 1]);
        }
    }
 
public : 
    segTree(vector<lli> a, lli sel){
        this->a = a;
        tree.reserve(4 * a.size() + 1);
        lazy.reserve(4 * a.size() + 1);
        for(int i = 0; i < 4 * a.size() + 1; i++){
            lazy[i] = 0;
        }
        this->sel = sel;
    }
 
    void build(){
        build(1, 0, a.size() - 1);
    }
 
    long long int query(lli l, lli r){
        return query(1, 0, a.size() - 1, l, r);
    }
 
    void update(lli l, lli r, lli inc){
        update(1, 0, a.size() - 1, l, r, inc);
    }
 
    void update(lli pos, lli inc){
        update(pos, pos, inc);
    }
 
};
 
lli power(lli b, lli p, lli m = mod){
    lli res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * b) % m;
        }
        b = (b * b) % m;
        p = p>>1;
    }
    return res;
}
 
lli modInverse(lli n, lli m = mod){
    return power(n, m - 2, m);
}
 
bool mySort(pair<int, int> p1, pair<int, int> p2){ // for ascending with respect to both parameters
    if(p1.first < p2.first){
        return true;
    }
    else if(p1.first == p2.first and p1.second < p2.second){
        return true;
    }
    return false;
}
 
lli lis(vector<lli> & v){
    lli n = v.size();
    vector<lli> dp(n);
    dp[0] = 1;
    lli ans = 1;
    for(int i = 1; i < n; i++){
        lli m = 0;
        for(int j = i - 1; j >= 0; j--){
            if(v[j] < v[i]){
                m = max(m, dp[j]);
            }
        }
        dp[i] = 1 + m;
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    return ans;
}
 
vector<lli> sieve(lli n){ // find all prime numbers <= n
    vector<bool> v(n + 1, false);
    v[2] = true;
    for(int i = 3; i <= n; i += 2){
        v[i] = true;
    }
    for(size_t i = 3; i <= n; i += 2){
        if(v[i]){
            for(size_t j = i * i; j <= n; j += 2 * i){
                v[j] = false;
            }
        }
    }
    v[1] = false;
    v[0] = false;
    vector<lli> primes;
    for(int i = 0; i < v.size(); i++){
        if(v[i]){
            primes.push_back(i);
        }
    }
    return primes;
}
 
lli gcd(lli a, lli b){
    while(b > 0){
        lli r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
lli lcm(lli a, lli b){
    lli g = gcd(a, b);
    return (a * b) / g;
}
 
vector<lli> segSieve(lli l, lli r){ // find prime numbers within a range l and r inclusive
    lli lim = sqrt(r);
    if(l < 2){
        l = 2;
    }
    vector<lli> s = sieve(lim);
    vector<bool> v(r - l + 1, true);
    for(lli i = 0; i < s.size(); i++){
        for(lli j = 0; j < v.size(); j++){
            if((j + l) % s[i] == 0 && (j + l) != s[i]){
                v[j] = false;
            }
        }
    }
    vector<lli> primes;
    for(int i = 0; i < v.size(); i++){
        if(v[i]){
            primes.push_back(i + l);
        }
    }
    return primes;
}
 
vector<pair<lli, lli>> primeFactors(lli n){ // returns all prime factors with along with their powers
    vector<lli> primes = sieve(sqrt(n) + 2);
    lli p;
    if(primes.size() > 0){
        p = primes[0];
    }
    else {
        p =  n + 1;
    }
    vector<pair<lli, lli>> f;
    int i = 0;
    while(i < primes.size() && p * p <= n){
        lli count = 0;
        while(p > 0 and n % p == 0){
            count++;
            n /= p;
        }
        if(count > 0){
            f.push_back(make_pair(p, count));
        }
        i++;
        if(i == primes.size()){
            break;
        }
        p = primes[i];
    }
    if(n > 1){ // number is itself prime
        f.push_back(make_pair(n, 1));
    }
    return f;
}
 
vector<lli> factors(lli n){ // returns all factors of a given number
    lli lim = sqrt(n);
    vector<lli> f;
    for(int i = 2; i <= lim; i++){
        if(n % i == 0){
            f.push_back(i);
            f.push_back(n / i);
        }
    }
    return f;
}
 
lli ceilAB(lli a, lli b){
    return (a + b - 1) / b;
}
 
lli low_bound(vector<lli> & v, lli start, lli end, lli n){ // returns index of first element less than or equal to n in sorted array
    if(start > end){
        return -1;
    }
    lli mid = (start + end) / 2;
    if(v[mid] == n){
        return mid;
    }
    else if(v[mid] > n){
        lli index = low_bound(v, start, mid - 1, n);
        return index;
    }
    else {
        lli index = low_bound(v, mid + 1, end, n);
        if(index == -1){
            return mid;
        }
        return index;
    }
}
 
void fastIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}
 
int main(void){
    fastIO();
    lli q, x;
    cin>>q>>x;
    set<pll> s;
    for(int i = 0; i < x; i++){
        s.insert(mp(0, i));
    }
    unordered_map<lli, lli> r;
    while(q--){
        lli n;
        cin>>n;
        n = n % x;
        s.erase(mp(r[n], n));
        r[n]++;
        s.insert(mp(r[n], n));
        pll ans = *s.begin();
        cout<<(ans.fi * x + ans.se)<<endl;
    }
    return 0;
}