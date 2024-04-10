#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=0;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='Q')
        {
            int q=0;
            for(int b=a+1; b<n; b++)
            {
                if(s[b]=='A') q++;
                if(s[b]=='Q') an+=q;
            }
        }
    }
    cout<<an;
}