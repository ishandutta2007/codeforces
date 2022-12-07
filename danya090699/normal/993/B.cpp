#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n][2], ar2[m][2];
    set <int> q[n], q2[m], an;
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    for(int a=0; a<m; a++) cin>>ar2[a][0]>>ar2[a][1];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int x=0;
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<2; j++) if(ar[a][i]==ar2[b][j]) x++;
            }
            if(x==1)
            {
                int ch;
                if(ar[a][0]==ar2[b][0]) ch=ar[a][0];
                else if(ar[a][0]==ar2[b][1]) ch=ar[a][0];
                else ch=ar[a][1];
                q[a].insert(ch), q2[b].insert(ch), an.insert(ch);
            }
        }
    }
    if(an.size()==1) cout<<(*an.begin());
    else
    {
        int ok=1;
        for(int a=0; a<n; a++) if(q[a].size()>1) ok=0;
        for(int a=0; a<m; a++) if(q2[a].size()>1) ok=0;
        if(ok) cout<<0;
        else cout<<-1;
    }


    /*for(int a=0; a<m; a++)
    {
        q2[a]=0;
        for(int b=0; b<n; b++)
        {
            int x=0;
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<2; j++) if(ar2[a][i]==ar[b][j]) x++;
            }
            if(x==1) q2[a]++;
        }
    }*/
}