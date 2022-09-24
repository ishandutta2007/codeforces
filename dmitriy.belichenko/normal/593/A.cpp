#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

static long parseans(long j, long l)
{
    string k = "";
    long cur = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}


static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    } else
    {
        return gcd(b, a % b);
    }
}

static bool pri(long long k)
{
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}

int n;
string ss[105];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> ss[i];
    int ans = 0;
    for (char a='a';a<='z';a++) for (char b='a';b<='z';b++) {
        int cur = 0;
        for (string s: ss) {
            bool ok = 1;
            for (char c: s) if (c!=a && c!=b) ok = 0;
            if (ok) cur+=s.size();
        }
        ans = max(ans,cur);
    }
    cout << ans << '\n';
    
    return 0;
}