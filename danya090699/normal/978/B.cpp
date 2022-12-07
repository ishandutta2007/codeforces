#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0, an=0;
    string s;
    cin>>n>>s;
    while(yk<n)
    {
        if(s[yk]=='x')
        {
            int q=0;
            while(yk<n)
            {
                if(s[yk]=='x')
                {
                    q++, yk++;
                }
                else break;
            }
            if(q>2) an+=q-2;
        }
        else yk++;
    }
    cout<<an;
}