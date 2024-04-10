#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            int sm[10][10];
            for(int a=0; a<10; a++) for(int b=0; b<10; b++) sm[a][b]=inf;
            for(int a=0; a<10; a++)
            {
                sm[a][(a+i)%10]=1;
                sm[a][(a+j)%10]=1;
            }
            for(int a=0; a<10; a++)
            {
                for(int b=0; b<10; b++)
                {
                    for(int c=0; c<10; c++) sm[b][c]=min(sm[b][c], sm[b][a]+sm[a][c]);
                }
            }
            int an=0;
            for(int a=0; a+1<s.size(); a++)
            {
                int u=s[a]-'0', v=s[a+1]-'0';
                an=min(inf, an+sm[u][v]);
            }
            if(an==inf) an=-1;
            else an-=s.size()-1;

            cout<<an<<" ";
        }
        cout<<"\n";
    }
}