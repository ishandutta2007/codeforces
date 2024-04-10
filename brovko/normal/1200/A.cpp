#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[15];
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        if(c=='L')
        {
            int j=0;
            while(a[j])
                j++;
            a[j]++;
        }
        if(c=='R')
        {
            int j=9;
            while(a[j])
                j--;
            a[j]++;
        }
        if(c>='0' && c<='9')
            a[c-'0']=0;
    }
    for(int i=0;i<10;i++)
        cout << a[i];
}