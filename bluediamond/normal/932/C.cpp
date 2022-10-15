#include <bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int n,a,b,nr_a,nr_b;
bool ok=0;
int main()
{
    cin>>n>>a>>b;
    for(int i=0;i*a<=n;i++)
    {
        if((n-i*a)%b==0)
        {
            ok=1;
            nr_a=i;
            nr_b=(n-i*a)/b;
            break;
        }
    }
    if(ok==0)
    {
        cout<<-1;
        return 0;
    }
    int left=0;
    for(int i=1;i<=nr_a;i++)
    {
        int st,dr;
        st=left+1;
        dr=left+a;
        for(int j=st;j<dr;j++)
            cout<<j+1<<" ";
        cout<<st<<" ";
        left=dr;
    }
    for(int i=1;i<=nr_b;i++)
    {
        int st,dr;
        st=left+1;
        dr=left+b;
        for(int j=st;j<dr;j++)
            cout<<j+1<<" ";
        cout<<st<<" ";
        left=dr;
    }
    return 0;
}