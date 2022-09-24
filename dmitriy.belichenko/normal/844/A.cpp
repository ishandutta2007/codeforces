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
    int k;
    set<char> m;
    string s;
    cin >> s >> k;
    for(int i = 0; i < s.size(); i++)
    {
        m.insert(s[i]);
    }
    int a = m.size();
    if(s.size() < k)
    {
        cout << "impossible";
        return 0;
    }
    if(a >= k)
    {
        cout << 0;
        return 0;
    }
    cout << k - a;
    
}