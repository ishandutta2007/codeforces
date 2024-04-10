#include <bits/stdc++.h>

using namespace std;

const int L=31;
int n;
int t[2][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<L;i++)
    {
        t[0][i]=0;
        t[1][i]=1;
    }
    int mabit=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        int x;
        cin>>s>>x;
        for(int bt=0;bt<L;bt++)
        {
            int val;
            if(x&(1<<bt))
                val=1,mabit=max(mabit,bt);
            else
                val=0;
            if(s=="|") t[0][bt]|=val,t[1][bt]|=val;
            if(s=="&") t[0][bt]&=val,t[1][bt]&=val;
            if(s=="^") t[0][bt]^=val,t[1][bt]^=val;
        }
    }
    int ans1=0;
    int ans2=0;
    for(int bt=0;bt<10;bt++)
    {
        if(t[0][bt]==1 && t[1][bt]==0) ans2+=(1<<bt);
        if(t[0][bt]==0 && t[1][bt]==0) ans1+=(1<<bt),ans2+=(1<<bt);
        if(t[0][bt]==1 && t[1][bt]==1) ans1+=(1<<bt);
    }
    cout<<"2\n";
    cout<<"| "<<ans1<<"\n";
    cout<<"^ "<<ans2<<"\n";
    return 0;
}
/**
**/