#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
#define MAXN 10005

int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,l,r,x;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<m;i++)
    {
        cin >> l >> r >> x;
        l--,r--,x--;
        int c=0;
        for(int j=l;j<=r;j++)
            if(arr[j]<arr[x])
                c++;
        if(c==x-l)
            db("Yes")
        else
            db("No")
    }

    return 0;
}