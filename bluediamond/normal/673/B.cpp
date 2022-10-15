#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000+5;
int n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m==0)
    {
        cout<<n-1<<"\n";
        return 0;
    }
    int st,dr;
    cin>>st>>dr;
    if(st>dr)
        swap(st,dr);
    for(int i=2;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        st=max(st,a);
        dr=min(dr,b);
    }
    if(dr-st<0)
        cout<<"0\n";
    else
        cout<<dr-st<<"\n";
    return 0;
}