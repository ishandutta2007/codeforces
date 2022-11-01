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
        string x;
        cin >> x;
        int a=0,b=0;
        int res=0;
        for(char c:x)
        {
            if(c=='(') a++;
            else if(c==')')
            {
                if(a>0)
                {
                    a--;
                    res++;
                }
            }
            else if(c=='[') b++;
            else if(c==']')
            {
                if(b>0)
                {
                    b--;
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}