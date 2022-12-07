#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string va[n];
    int sv[n][3];
    map <string, int> ma;
    for(int a=0; a<n; a++)
    {
        string na, te;
        cin>>na;
        ma[na]=ma.size()-1;
        cin>>te>>te;
        if(te[0]=='0' or te[0]=='1') va[a]=te;
        else
        {
            if(te=="?") sv[a][0]=-1;
            else sv[a][0]=ma[te];
            cin>>te;
            if(te=="AND") sv[a][1]=0;
            if(te=="OR") sv[a][1]=1;
            if(te=="XOR") sv[a][1]=2;
            cin>>te;
            if(te=="?") sv[a][2]=-1;
            else sv[a][2]=ma[te];
        }
    }
    bool an[m], an2[m];
    for(int a=0; a<m; a++)
    {
        int su[2];
        su[0]=0, su[1]=0;
        for(int b=0; b<2; b++)
        {
            bool cu[n];
            for(int c=0; c<n; c++)
            {
                if(va[c].size()!=0)
                {
                    if(va[c][a]=='0') cu[c]=0;
                    else cu[c]=1;
                }
                else
                {
                    bool lv, rv;
                    if(sv[c][0]==-1) lv=b;
                    else lv=cu[sv[c][0]];
                    if(sv[c][2]==-1) rv=b;
                    else rv=cu[sv[c][2]];
                    if(sv[c][1]==0) cu[c]=(lv&rv);
                    if(sv[c][1]==1) cu[c]=(lv|rv);
                    if(sv[c][1]==2) cu[c]=(lv^rv);
                }
                su[b]+=cu[c];
            }
        }
        if(su[0]<su[1])
        {
            an[a]=0, an2[a]=1;
        }
        else if(su[0]>su[1])
        {
            an[a]=1, an2[a]=0;
        }
        else
        {
            an[a]=0, an2[a]=0;
        }
    }
    for(int a=0; a<m; a++) cout<<an[a];
    cout<<"\n";
    for(int a=0; a<m; a++) cout<<an2[a];
}