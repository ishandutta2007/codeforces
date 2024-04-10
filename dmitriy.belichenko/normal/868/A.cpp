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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c1 , c2;
    cin >> c1 >> c2;
    int n;
    bool f1 = 0,f2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s[1] == c1) f2 = 1;
        if(s[0] == c2) f1 = 1;
        if(s[0] == c1 && s[1] == c2)
        {
            f1 = 1;
            f2 = 1;
        }
        
    }
    if(f1 && f2) cout << "YES" << "\n";
    else cout << "NO"  << "\n";
    return 0;
}