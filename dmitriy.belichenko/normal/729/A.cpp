#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
long long inf = 1LL << 62;
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
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
int n , k;

using namespace std;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '111111111111';
    vector<pair<int, int> >g;
    vector<pair<int, int > > bl;
    for(int i = 0; i < n ; i++) {
        if(s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
            g.push_back({i, i + 2});
            
        }
    }
    for(int i = 0; i < g.size(); i++) {
        if(bl.size() == 0) {
            bl.push_back(g[0]);
            continue;
        }
        int st = g[i].first;
        int ed = bl[bl.size() - 1].second;
        if(st == ed) {
            bl[bl.size() - 1].second = g[i].second;
        } else {
            bl.push_back(g[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        int p = - 1;
        for(int j = 0; j < bl.size(); j++) {
            if(i == bl[j].first) {
                p = j;
                break;
            }
        }
        if(p == -1) {
            cout << s[i];
            continue;
        }
        cout<< "***";
        i = bl[p].second;
    }
    return 0;
}