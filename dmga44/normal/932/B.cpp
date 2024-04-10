#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 1000005

int arr[MAXN],ar[MAXN],a[MAXN][10];

int f(int n)
{
    vector<int> d;
    while(n)
    {
        d.push_back(n%10);
        n/=10;
    }
    int res=1;
    for(auto y : d)
        if(y)
            res*=y;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    db("gjn")
    for(int i=1;i<MAXN;i++)
        arr[i]=f(i);
    for(int i=1;i<MAXN;i++)
    {
        if(arr[i]<10)
            ar[i]=arr[i];
        else
            ar[i]=ar[arr[i]];
        for(int j=0;j<10;j++)
            a[i][j]=a[i-1][j];
        a[i][ar[i]]++;
    }

    int q,l,r,k;
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> k;
        db(a[r][k]-a[l-1][k])
    }

    return 0;
}