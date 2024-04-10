#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,x;
    cin >> n >> x;
    int res=0;
    for(int i=1;i<=n;i++)
        if(x%i==0 && x/i<=n)
            res++;
    db(res)

    return 0;
}