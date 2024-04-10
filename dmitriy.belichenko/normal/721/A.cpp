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

int n;
int c=0;
int f[130][130][130];
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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = 0;
    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'B') cnt++;
        else
        {
            flag = 1;
            if(cnt) ans.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt) ans.push_back(cnt);
    if(flag)
    {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    }
    else
    {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    }

}