#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q[5][2], po=1, an=0;
    cin>>n;
    for(int a=0; a<5; a++)
    {
        q[a][0]=0, q[a][1]=0;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        x--;
        q[x][0]++;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        x--;
        q[x][1]++;
    }
    for(int a=0; a<5; a++)
    {
        int di=q[a][0]-q[a][1];
        if(di<0) di*=-1;
        an+=di/2;
        if(di%2==1) po=0;
    }
    if(po) cout<<an/2;
    else cout<<-1;
}