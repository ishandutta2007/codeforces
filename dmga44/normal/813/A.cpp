#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef unsigned long long ull;

int a[100005];
bool arr[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,l,r;
    ull sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    cin >> m;
    int d=-1,nnn=1;
    for(int i=0;i<m && nnn;i++)
    {
        cin >> l >> r;
        for(int j=l;j<=r && nnn;j++)
        {
            arr[j]=true;
            if(j>=sum)
                d=j,nnn=0;
        }
    }

    db(d)

    return 0;
}