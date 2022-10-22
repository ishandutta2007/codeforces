#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,res=0,n,x;
    cin >> a >> b >> c >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        if(x>b && x<c)
            res++;
    }
    db(res)

    return 0;
}