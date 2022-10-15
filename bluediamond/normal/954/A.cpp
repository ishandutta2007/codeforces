#include <bits/stdc++.h>

using namespace std;

int n;
char ch;
int last=-1,ans;
int main()
{
    cin>>n;
    cin.get();
    ch=cin.get();
    if(ch=='R')last=1;
    else
        last=2;
    ans=1;
    for(int i=2;i<=n;i++)
    {
        int key;
        ch=cin.get();
        if(ch=='R')key=1;
        else
            key=2;
        if(key!=last && last!=-1)
            last=-1;
        else
        {
            last=key;
            ans++;
        }
    }cout<<ans;
    return 0;
}
/**
**/