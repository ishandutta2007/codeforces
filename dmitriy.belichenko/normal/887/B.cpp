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

int main()
{
    srand(time(0));
    int n;
    cin >> n;
    vector<int> a[3];
    vector<int> id = {0 , 1 , 2 };
    for(int i = 0; i < n; i++)
    {
        a[i].resize(6);
        for(int j = 0; j < 6; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = n; i < 3; i++)
    {
        a[i].resize(6);
        for(int j = 0; j < 6; j++)
        {
            a[i][j] = -1000;
        }
    }
    set<int> ans;
   
        while (true)
        {
            for(int j = 0; j < 6; j++)
            {
                int d1 = a[id[0]][j];
                ans.insert(d1);
                if( n > 1)
                for(int k = 0; k < 6; k++)
                {
                    int d2 = a[id[1]][k];
                    ans.insert(10 * d1 + d2);
                    if(n > 2)
                    for(int u = 0; u < 6; u++)
                    {
                        int d3 = a[id[2]][u];
                        ans.insert(d3);
                        ans.insert(100 * d1 + 10 * d2 + d3);
                        
                    }
                }
            }
            
            if(!next_permutation(id.begin(), id.end())) break;
    }
    int res = 0;
    for(int i = 1; i < 100000; i++)
    {
        if(ans.count(i) != 1)
        {
            cout << i - 1 << "\n";
            break;
        }
    }
    return 0;
}