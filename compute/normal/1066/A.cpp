#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int L,v,l,r;
        scanf("%d%d%d%d",&L,&v,&l,&r);
        int tot=L/v;
        int first=ceil(1.0*l/v);
        int last=r/v;
        int ans=tot-(last-first+1);
        cout<<ans<<endl;

    }
}