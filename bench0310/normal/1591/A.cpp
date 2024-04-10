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
        bool ok=1;
        int h=1;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a==0)
            {
                if(i>1&&p==0) ok=0;
            }
            else h+=(1+4*(p==1));
            p=a;
        }
        if(!ok) h=-1;
        cout << h << "\n";
    }
    return 0;
}