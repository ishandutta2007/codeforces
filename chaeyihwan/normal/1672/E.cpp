#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int ask(int w)
{
    cout << "? " << w << endl;
    int k; cin >> k;
    return k;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    int l = 1, r = 1000000000;
    while(l < r)
    {
        int mid = (l + r)/2;
        int x = ask(mid);
        if(x == 1) r = mid;
        else l = mid + 1;
    }
    
    int X = l;
    int ans = X;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if((X-j)%i == 0)
            {
                int k = ask((X-j)/i);
                if(k == i) ans = min(ans, X-j);
            }
        }
    }
    
    cout << "! " << ans << endl;
}