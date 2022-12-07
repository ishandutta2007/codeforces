#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0;
    string s;
    cin>>n>>s;
    while(yk<n)
    {
        if(s[yk]=='a' or s[yk]=='e' or s[yk]=='i' or s[yk]=='o' or s[yk]=='u' or s[yk]=='y')
        {
            cout<<s[yk];
            while(yk<n)
            {
                if(s[yk]=='a' or s[yk]=='e' or s[yk]=='i' or s[yk]=='o' or s[yk]=='u' or s[yk]=='y') yk++;
                else break;
            }
        }
        else
        {
            cout<<s[yk];
            yk++;
        }
    }
}