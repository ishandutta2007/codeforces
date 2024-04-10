#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;

static long parseans(long j, long l)
{
    string k = "";
    long ps = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        ps *= 10;
        ps += k[i] - '0';
    }
    return ps;
}

int cur = 1;
int cnt = 0;
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
int n , k;
string equal(string s)
{
    if (s.size() % 2 == 1) return s;
    string s1 = equal(s.substr(0, s.size()/2));
    string s2 = equal(s.substr(s.size()/2, s.size()));
    if (s2 > s1) return s2 + s1;
    else return s1 + s2;
}

int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
  //  cout << equal(s1) << " " << equal(s2) << "\n";
    if(equal(s1) == equal(s2) ) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}