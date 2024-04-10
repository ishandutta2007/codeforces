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

    int n;
    cin >> n;
    int res=0,ok=1,ant,lant=-1;
    cin >> ant;
    n--;
    while(n--)
    {
        int x;
        cin >> x;
        if(x+ant==5)
            ok=0;
        if(x==1)
            res+=ant+1;
        if(ant==1)
        {
            res+=x+1;
            if(x==2 && lant==3)
                res--;
        }
        lant=ant;
        ant=x;
    }
    if(ok)
    {
        db("Finite")
        cout << res << '\n';
    }
    else
        cout << "Infinite\n";

    return 0;
}