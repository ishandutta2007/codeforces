#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
#define MAXN 100005

int x[MAXN],y[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];

    int m=0,r=0;
    for(int i=0;i<n;i++)
    {
        if(x[i]>0)
            r++;
        else
            m++;
    }

    if(r<=1 || m<=1)
        db("Yes")
    else
        db("No")
    return 0;
}