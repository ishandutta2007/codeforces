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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int>a(n);
    int non = 0;
    int cnt = 0;
    if(n % 2 == 0 )
    {
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(a[i] % 2) non++;
        else cnt++;
    }
    if(a[0] % 2 == 1 && a[n-1] % 2 == 1 )
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}