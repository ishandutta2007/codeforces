#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int h, w, an=1;
    cin>>h>>w;
    int fi[h][w];
    for(int a=0; a<h; a++)
    {
        for(int b=0; b<w; b++) fi[a][b]=-1;
        int q;
        cin>>q;
        for(int b=0; b<q; b++) fi[a][b]=1;
        if(q<w) fi[a][q]=0;
    }
    for(int a=0; a<w; a++)
    {
        int q;
        cin>>q;
        for(int b=0; b<q; b++)
        {
            if(fi[b][a]==0) an=0;
            else fi[b][a]=1;
        }
        if(q<h)
        {
            if(fi[q][a]==1) an=0;
            else fi[q][a]=0;
        }
    }
    for(int a=0; a<h; a++) for(int b=0; b<w; b++) if(fi[a][b]==-1) an=(an*2)%mod;
    cout<<an;
}