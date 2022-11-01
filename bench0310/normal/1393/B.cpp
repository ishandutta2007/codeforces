#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    int n;
    cin >> n;
    int two=0;
    int four=0;
    vector<int> c(N+1,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        c[a]++;
    }
    for(int i=1;i<=N;i++)
    {
        two+=(c[i]/2);
        if(c[i]>=4) four++;
    }
    int q;
    cin >> q;
    while(q--)
    {
        char t;
        int a;
        cin >> t >> a;
        if(t=='+')
        {
            two-=(c[a]/2);
            four-=(c[a]>=4);
            c[a]++;
            two+=(c[a]/2);
            four+=(c[a]>=4);
        }
        else
        {
            two-=(c[a]/2);
            four-=(c[a]>=4);
            c[a]--;
            two+=(c[a]/2);
            four+=(c[a]>=4);
        }
        if(four>=1&&two-2>=2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}