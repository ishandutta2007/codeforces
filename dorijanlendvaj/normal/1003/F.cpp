/*
 ID: bradyawn
 PROG: contest
 LANG: C++11
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef pair<ll,ll> ll2;

const ll mod = 1824261409;

ll mpow(ll a, ll b) //a ^ b % mod
{
    if (b == 0) return 1;
    if (b == 1) return a%mod;
    
    ll x = mpow(a, b/2);
    
    if (b&1) return (x%mod * x%mod * a%mod);
    return (x%mod * x%mod);
}

ll f(string &s) //hashing function
{
    ll ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret += (s[i]-'a'+1)*mpow(27, i);
        ret %= mod;
    }
    return ret;
}

ll a[301];

int len[301];

map<vector<int>, int> cnt; //n^2 amnt
map<vector<int>, vector<i2>> pos;


int main()
{
    //ifstream inf("");
    //ofstream outf("");
    //cout << setprecision(10);
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    
    int orig = 0;
    
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        a[i] = f(s);
        len[i] = (int)s.size();
        orig += len[i];
        if (i != 1) orig++;
    }
    
    //for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i==n];
    
    int cut = 0;
    
    for (int sz = 1; sz <= n; sz++)
        for (int i = 1; i+sz-1 <= n; i++)
        {
            vector<int> pat;
            for (int j = i; j <= i+sz-1; j++) pat.push_back(a[j]);
            cnt[pat]++;
            pos[pat].push_back(make_pair(i+sz-1, i));
        }
    
    for (auto e : cnt) //n^2
    {
        
        vector<i2> vec = pos[e.first];
        
        
        sort(vec.begin(), vec.end());
        
        int occ = 1;
        int lst = 0;
        
        //cout << "pattern: "; for (auto u : e.first) cout << u << ' '; cout << '\n';
        
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].second <= vec[lst].first) continue;
            occ++;
            lst = i;
        }
        
        if (occ < 2) continue; //0 or 1
        
        i2 p = vec[0];
        
        int a = p.second;
        int b = p.first;
        
        //how much from shortening one occurences
        int v = 0;
        for (int i = a; i <= b; i++) v += len[i]-1;
        v += (b-a);
        
        //every occurence
        v *= occ;
        
        cut = max(v, cut);
    }
    
    //cout << cut << endl;
    
    cout << orig-cut << '\n';
    
    return 0;
    
}