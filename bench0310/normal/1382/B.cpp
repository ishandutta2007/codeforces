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
        int n;
        cin >> n;
        int p=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a>1&&p==0) p=i;
        }
        int win=0;
        if(p!=0) win=(p&1);
        else win=(n&1);
        if(win==1) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}