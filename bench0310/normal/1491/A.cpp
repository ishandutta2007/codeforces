#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    array<int,2> c={0,0};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    while(q--)
    {
        int t,x;
        cin >> t >> x;
        if(t==1)
        {
            c[a[x]]--;
            a[x]=1-a[x];
            c[a[x]]++;
        }
        else
        {
            if(x<=c[1]) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}