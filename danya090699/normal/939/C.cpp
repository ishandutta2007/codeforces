#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q[n], add[n+1];
    for(int a=0; a<n; a++)
    {
        cin>>q[a], add[a]=0;
    }
    add[n]=0;
    int s, f;
    cin>>s>>f;
    s--, f-=2;
    for(int a=0; a<n; a++)
    {
        int s2=s-a, f2=f-a;
        if(s2<0) s2+=n;
        if(f2<0) f2+=n;
        if(f2>=s2)
        {
            add[s2]+=q[a], add[f2+1]-=q[a];
        }
        else
        {
            add[s2]+=q[a], add[n]-=q[a], add[0]+=q[a], add[f2+1]-=q[a];
        }
    }
    int cu=0, be=-1, an;
    for(int a=0; a<n; a++)
    {
        cu+=add[a];
        if(cu>be)
        {
            be=cu, an=a+1;
        }
    }
    cout<<an;
}