#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int> a,v;
signed main()
{
    int n=read(),m=sqrt(n);
    for(int i=1; i<=m; i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(n/i>i) v.push_back(n/i);
        }
    }
    for(int i:v)
    {
        int x=i,y=n/x;
        int A=(1+n-x+1)*y/2;
        a.push_back(A);
    }
    sort(a.begin(),a.end());
    for(int x:a) printf("%lld ",x);
    return 0;
}