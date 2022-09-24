#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

const int N = 1e3;
const int INF = 1e9;

long long gen(long long x) {
    return x * (x + 1) / 2;
}

int main()
{
    ::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "z";
    int k;
    cin >> k;
    for (char c = 'a'; k && c <= 'z'; ++c) {
        int l = 0, r = k + 100;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (gen(mid) <= k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        for (int i = 0; i <= l; ++i)
            s.push_back(c);
        k -= gen(l);
    }
    cout << s << endl;

    return 0;
}