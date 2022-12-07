#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, inf=1e9, an;
    cin>>n>>m;
    an=inf;
    int ar[n][m], bcol[m], bro[n];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>ar[a][b];
    for(int a=0; a<=500; a++)
    {
        int ar2[n][m], col[m], ro[n], pos=1, cu=a;
        ro[0]=a;
        for(int b=0; b<m; b++)
        {
            col[b]=ar[0][b]-a;
            cu+=col[b];
            if(col[b]<0) pos=0;
        }
        for(int b=1; b<n; b++)
        {
            ro[b]=ar[b][0]-col[0];
            if(ro[b]<0) pos=0;
            cu+=ro[b];
            for(int c=0; c<m; c++) if(ar[b][c]!=ro[b]+col[c]) pos=0;
        }
        if(pos)
        {
            if(cu<an)
            {
                an=cu;
                for(int b=0; b<m; b++) bcol[b]=col[b];
                for(int b=0; b<n; b++) bro[b]=ro[b];
            }
        }
    }
    if(an!=inf)
    {
        cout<<an<<"\n";
        for(int a=0; a<m; a++)
        {
            for(int b=0; b<bcol[a]; b++) cout<<"col "<<a+1<<"\n";
        }
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<bro[a]; b++) cout<<"row "<<a+1<<"\n";
        }
    }
    else cout<<-1;
}