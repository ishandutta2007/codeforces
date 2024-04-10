
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
    int n , last = 0;
    cin >> n;
    vector<int> prev(105);
    vector<int> next(105);
    
    for(int i = 1; i <= n; i++) cin >> prev[i] >> next[i];
    for(int i = 1; i <= n; i++)
    if(prev[i] == 0)
    {
        int t = i;
        for(; next[t] ; t = next[t]);
        if(!last)
        {
            last=t;
        }
        else
        {
            prev[i] = last;
            next[last] = i;
            last = t;
        }
    }
    for(int i = 1 ;i <= n ; i++) cout << prev[i] << " " << next[i] << "\n";
    return 0;

}