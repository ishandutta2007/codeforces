
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
    int n ;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    int j = n - 1;
    while(i < j)
    {
        while( i < j && a[i] < a[i+1] ) i++;
        while( j > i && a[j] < a[j-1] ) j--;
        if(i == j) break;
        if(a[i] < a[j])
        {
            ans += (a[ i ] - a[i + 1]) + 1;
            a[ i + 1] = a[ i ] + 1;
        }
        else
        {
            ans += a[j] - a[j - 1] + 1;
            a[j - 1] = a[j] + 1;
        }
    }
   // for(int i = 0; i < n ; i++) cout << a[i] << " ";
   // cout << "\n";
    cout << ans << "\n";
    return 0;

}