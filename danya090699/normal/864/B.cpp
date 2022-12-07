//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, yk=0;
    cin>>n;
    string s;
    cin>>s;
    while(yk<n)
    {
        if(s[yk]>='a' and s[yk]<='z')
        {
            set <char> se;
            while(yk<n)
            {
                if(s[yk]>='a' and s[yk]<='z')
                {
                    se.insert(s[yk]), yk++;
                }
                else break;
            }
            int q=se.size();
            an=max(an, q);
        }
        else yk++;
    }
    cout<<an;
}