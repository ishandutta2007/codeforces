#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, le=0;
    string s;
    cin>>n>>k>>s;
    for(int a=0; a<n; a++)
    {
        if(k)
        {
            if(s[a]=='(')
            {
                if(k-1-(le+1)>=0)
                {
                    le++, k--;
                    cout<<"(";
                }
            }
            else
            {
                if(le)
                {
                    le--, k--;
                    cout<<")";
                }
            }
        }
    }
}