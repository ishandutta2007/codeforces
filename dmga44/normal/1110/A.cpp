#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int b,k;
    cin >> b >> k;
    int res=0,a;
    for(int i=0;i<k;i++)
    {
        cin >> a;
        res*=b;
        res+=a;
        res%=2;
    }

    if(res)
        db("odd")
    else
        db("even")

    return 0;
}