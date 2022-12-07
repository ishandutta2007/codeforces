#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int an=1e9;
    string s[4][n];
    for(int a=0; a<4; a++)
    {
        for(int b=0; b<n; b++) cin>>s[a][b];
    }
    for(int a=0; a<4; a++)
    {
        for(int b=a+1; b<4; b++)
        {
            int cu=0;
            for(int c=0; c<4; c++)
            {
                for(int d=0; d<n; d++)
                {
                    for(int e=0; e<n; e++)
                    {
                        if(c==a or c==b)
                        {
                            if(((d+e)&1)==(s[c][d][e]-'0')) cu++;
                        }
                        else
                        {
                            if(((d+e)&1)!=(s[c][d][e]-'0')) cu++;
                        }
                    }
                }
            }
            an=min(an, cu);
        }
    }
    cout<<an;
}