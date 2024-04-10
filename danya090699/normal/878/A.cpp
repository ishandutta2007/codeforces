#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    bool st[2][10];
    for(int a=0; a<10; a++)
    {
        st[0][a]=0, st[1][a]=1;
    }
    for(int a=0; a<n; a++)
    {
        char sy;
        int x;
        cin>>sy;
        scanf("%d", &x);
        for(int b=0; b<10; b++)
        {
            int cu=((x&(1<<b))>0);
            if(sy=='&')
            {
                st[0][b]&=cu;
                st[1][b]&=cu;
            }
            if(sy=='|')
            {
                st[0][b]|=cu;
                st[1][b]|=cu;
            }
            if(sy=='^')
            {
                st[0][b]^=cu;
                st[1][b]^=cu;
            }
        }
    }
    cout<<3<<"\n";
    cout<<"& ";
    int x=0;
    for(int a=0; a<10; a++)
    {
        if(st[0][a]==0 and st[1][a]==0) x+=0;
        else x+=(1<<a);
    }
    cout<<x<<"\n";
    cout<<"| ";
    x=0;
    for(int a=0; a<10; a++)
    {
        if(st[0][a]==1 and st[1][a]==1) x+=(1<<a);
    }
    cout<<x<<"\n";
    cout<<"^ ";
    x=0;
    for(int a=0; a<10; a++)
    {
        if(st[0][a]==1 and st[1][a]==0) x+=(1<<a);
    }
    cout<<x;
}