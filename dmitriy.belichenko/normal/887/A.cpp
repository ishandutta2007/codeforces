#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
#include<bitset>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#define fst first
#define snd second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define sq(a) (long double)a * a
using namespace std;
typedef long long ll;
const int N = 100005;
pair<long long, int> t[400005], d[400005], t1[400005], t2[400005];
long long n, a[100005];

int main()
{
    srand(time(0));
    string s;
    cin >> s;
    if(s.size() < 7)
    {
        cout << "no" << "\n";
        return 0;
    }
    int p = -1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            p = i;
            break;
        }
    }
    int cnt = 0;
    for(int i = p; i < s.size(); i++)
    {
        if(s[i] == '0') cnt++;
    }
    if(cnt >= 6)
    cout << "yes" << "\n";
    else cout << "no" << "\n";
    return 0;
}