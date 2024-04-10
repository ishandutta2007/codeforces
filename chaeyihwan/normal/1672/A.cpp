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

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            int a; cin >> a;
            sum += a-1;
        }
        
        if(sum%2 == 0) cout << "maomao90\n";
        else cout << "errorgorn\n";
    }
}