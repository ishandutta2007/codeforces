#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a[2],i;
    cin >> a[0] >> a[1];
    bool res=true;
    for(i=1;res;i++)
    {
        if(a[!(i&1)]<i)
            res=false;
        else
            a[!(i&1)]-=i;
    }

    if(i&1)
        db("Valera")
    else
        db("Vladik")

    return 0;
}