#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,x,b,y;
    cin >> n >> a >> x >> b >> y;
    a--,x--,b--,y--;
    bool res=(a==b);
    while(a!=x && b!=y)
    {
        a=(a+1)%n;
        b=(b-1+n)%n;
        res|=(a==b);
    }
    if(res)
        db("YES")
    else
        db("NO")

    return 0;
}