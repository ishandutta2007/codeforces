#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    set <char> se;
    char s[n];
    for(int a=0; a<n; a++)
    {
        cin>>s[a], se.insert(s[a]);
    }
    if(k>n)
    {
        for(int a=0; a<n; a++) cout<<s[a];
        for(int a=0; a<k-n; a++) cout<<*se.begin();
    }
    else
    {
        char an[k];
        bool fo=0;
        for(int a=k-1; a>=0; a--)
        {
            if(fo) an[a]=s[a];
            else
            {
                auto it=se.upper_bound(s[a]);
                if(it==se.end()) an[a]=*se.begin();
                else
                {
                    an[a]=*it, fo=1;
                }
            }
        }
        for(int a=0; a<k; a++) cout<<an[a];
    }
}