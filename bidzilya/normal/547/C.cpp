#include <bits/stdc++.h>
using namespace std;

const int kMaxA = 5e5;

vector<int> dels;
vector<int> primes;
vector<int> prime_index;

// 6 different prime divisors

vector<int> GetDels(int x)
{
    vector<int> r;
    while (x > 1 && dels[x] != -1) {
        r.push_back(dels[x]);
        int z = dels[x];
        while (x % z == 0) {
            x /= z;
        }
    }
    if (x > 1) {
        r.push_back(x);
    }
    return r;
}

const int kMaxAmountOfBits = 6;
const int kMaxMask = (1 << kMaxAmountOfBits);

int amount_of_bits[kMaxMask];

inline int GetAmountOfBits(int mask)
{
    int r = 0;
    while (mask > 0) {
        r += (mask & 1);
        mask >>= 1;
    }
    return r;
}

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

inline int GetNumber(const vector<int>& a, int mask)
{
    int res = 1;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (GetBit(mask, i)) {
            res *= a[i];
        }
    }
    return res;
}

inline int GetFromMap(map<int, int>& m, int x)
{
    if (m.find(x) != m.end()) {
        return m[x];
    } else {
        return 0;
    }
}

inline void UpdateInMap(map<int, int>& m, int x, int val)
{
    int& y = m[x];
    y += val;
    if (y == 0) {
        m.erase(x);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    for (int mask = 0; mask < kMaxMask; ++mask) {
        amount_of_bits[mask] = GetAmountOfBits(mask);
    }
    
    dels.resize(kMaxA + 1, -1);
    for (int i = 2; i * i <= kMaxA; ++i) {
        if (dels[i] == -1) {
            for (int j = i * i; j <= kMaxA; j += i) {
                dels[j] = i;
            }
        } 
    }
    prime_index.resize(kMaxA + 1);
    for (int i = 2; i <= kMaxA; ++i) {
        if (dels[i] == -1) {
            primes.push_back(i);
            prime_index[i] = primes.size() - 1;
        }
    }
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<bool> used(n, false);
    long long ans = 0;
    
    map<int, int> mp;
    
    for (; q; --q) {
        int id;
        cin >> id;
        --id;
        
        vector<int> r = GetDels(a[id]);
    
        long long cur_ans;
        if (!used[id]) {
            cur_ans = 0;
            for (int mask = 0; mask < (1 << (int) r.size()); ++mask) {
                int cc = GetNumber(r, mask);
                if (amount_of_bits[mask] & 1) {
                    cur_ans -= GetFromMap(mp, cc);
                } else {
                    cur_ans += GetFromMap(mp, cc);
                }
            }
    
            for (int mask = 0; mask < (1 << (int) r.size()); ++mask) {
                int cc = GetNumber(r, mask);
                UpdateInMap(mp, cc, +1);
            }
            used[id] = true;
        } else {
            for (int mask = 0; mask < (1 << (int) r.size()); ++mask) {
                int cc = GetNumber(r, mask);
                UpdateInMap(mp, cc, -1);
            }
            used[id] = false;
            cur_ans = 0;
            for (int mask = 0; mask < (1 << (int) r.size()); ++mask) {
                int cc = GetNumber(r, mask);
                if (amount_of_bits[mask] & 1) {
                    cur_ans += GetFromMap(mp, cc);
                } else {
                    cur_ans -= GetFromMap(mp, cc);
                }
            }
        }
        ans += cur_ans;
        cout << ans << '\n';
    }
    cout.flush();
    
    
    return 0;
}