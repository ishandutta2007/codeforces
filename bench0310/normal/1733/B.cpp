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
        int n,x,y;
        cin >> n >> x >> y;
        if(x>y) swap(x,y);
        if(x==0&&y!=0&&((n-1)%y)==0)
        {
            int a=2;
            for(int i=1;i<=(n-1)/y;i++)
            {
                for(int j=0;j<y;j++) cout << a << " ";
                a+=y;
            }
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}