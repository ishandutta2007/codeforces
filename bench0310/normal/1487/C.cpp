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
        for(int i=1;i<=n;i++)
        {
            int w=(n-1)/2;
            int d=((n%2)==0);
            for(int j=i+1;j<=n;j++)
            {
                if(w>0)
                {
                    cout << "1 ";
                    w--;
                }
                else if(d==1)
                {
                    cout << "0 ";
                    d=0;
                }
                else cout << "-1 ";
            }
        }
        cout << "\n";
    }
    return 0;
}