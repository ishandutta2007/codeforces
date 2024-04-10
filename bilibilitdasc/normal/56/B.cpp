#include <bits/stdc++.h>
using namespace std;
int N,A[1005],L=114514,R=-1;
int main()
{
    cin>>N;
    for(int i=1;i<=N;++i)
    {
        cin>>A[i];
        if(A[i]!=i)
        {
            L=min(L,i);R=max(R,i);
        }
    }
    if(R==-1) return puts("0 0"),0;
    reverse(A+L,A+R+1);
    for(int i=1;i<=N;++i) if(A[i]!=i) return puts("0 0"),0;
    cout<<L<<" "<<R<<endl;
}