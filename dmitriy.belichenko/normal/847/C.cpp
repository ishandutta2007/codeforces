
#include<cstring>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie();
    cout.tie(0);
    ll n , k;
    cin >> n >> k;
    ll traingle = 1LL * ((n) * (n-1)) / 2;
    if(traingle < k)
    {
        cout << "Impossible" << "\n";
        return 0;
    }
    int cur = 1;
    int size = 0;
    int p = n;
    k = k + p;
    while(k > 0LL)
    {
        if(k >= n + cur - 1 )
        {
            cout << "(";
            cur++;
            n--;
            size++;
            k = k - cur + 1;
        }
        else
        {
            size++;
            cur--;
            cout << ")";
        }
    }
    while(cur > 1)
    {
        cout << ")";
        cur--;
    }
    cout << "\n";
    return 0;

}