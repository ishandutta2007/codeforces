#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,c0,c1,h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        array<int,2> a={0,0};
        for(char c:s) a[c-'0']++;
        if(c0<c1)
        {
            swap(c0,c1);
            swap(a[0],a[1]);
        }
        int res=0;
        if(h<c0-c1)
        {
            res+=a[0]*h;
            a[1]=n;
            a[0]=0;
        }
        cout << res+a[0]*c0+a[1]*c1 << "\n";
    }
    return 0;
}