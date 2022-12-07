//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <string, int> ma[10];
    string s[n];
    for(int a=0; a<n; a++)
    {
        cin>>s[a];
        for(int b=1; b<=9; b++)
        {
            for(int c=0; c+b<=9; c++)
            {
                string cu=s[a].substr(c, b);
                if(ma[b].find(cu)==ma[b].end()) ma[b][cu]=a;
                else if(ma[b][cu]!=a) ma[b][cu]=-1;
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        bool fo=0;
        for(int b=1; b<=9; b++)
        {
            for(int c=0; c+b<=9; c++)
            {
                string cu=s[a].substr(c, b);
                if(ma[b][cu]!=-1)
                {
                    cout<<cu<<"\n";
                    fo=1;
                    break;
                }
            }
            if(fo) break;
        }
    }
}