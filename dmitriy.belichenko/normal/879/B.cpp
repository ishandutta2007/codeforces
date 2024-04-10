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
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  5e5 + 1000;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;


pair<char, int> c[N];
int st[400], n;
int ans[3];
void calcans()
{
    for (int i = 0; i < 10; ++i)
    {
        if (!st[i])
        {
            ans[2] += 1 << i;
        }
        if (st[i] == 1)
        {
            ans[1] += 1 << i;
        }
        if (st[i] == 2)
        {
            ans[0] -= 1 << i;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cin >> n >> k;
   // calcans();
    //vector<int> a(n);
    int r = 0;
    queue<int> p;
    for(int i = 0; i < n; i++)
    {
        cin >> r;
        p.push(r);
    }
    int cnt = 0;
    int top = p.front();
    p.pop();
    while(cnt < k && cnt <= n)
    {
        int next = p.front();
        p.pop();
        if(next < top)
        {
            cnt++;
            p.push(next);
        }
        else
        {
           // if(cnt > n) break;
            cnt = 1;
            p.push(top);
            top = next;
        }
        
    }
   cout << top << "\n";
    return 0;
}