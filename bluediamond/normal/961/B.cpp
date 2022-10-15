#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int n,k;
int v[N+5];
bool viz[N+5];
int S[N+5],total,best=0;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        cin>>viz[i];
        total+=viz[i]*v[i];
        S[i]=S[i-1]+(1-viz[i])*v[i];
    }
    for(int i=1;i+k-1<=n;i++)
    {
        int st=i;
        int dr=i+k-1;
        best=max(best,S[dr]-S[st-1]);
    }
    cout<<best+total;
    return 0;
}
/**
**/