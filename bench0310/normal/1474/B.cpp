#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto p=[](int a)->bool
    {
        for(int i=2;i*i<=a;i++) if((a%i)==0) return 0;
        return 1;
    };
    int t;
    cin >> t;
    while(t--)
    {
        int d;
        cin >> d;
        int one=1;
        for(int x=d+1;;x++)
        {
            if(p(x))
            {
                one=x;
                break;
            }
        }
        int two=1;
        for(int x=one+d;;x++)
        {
            if(p(x))
            {
                two=x;
                break;
            }
        }
        cout << one*two << "\n";
    }
    return 0;
}