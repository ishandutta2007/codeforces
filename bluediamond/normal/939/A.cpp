#include <bits/stdc++.h>
using namespace std;
const int nmax=5000;
int n,place[nmax+5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>place[i];
    for(int i=1;i<=n;i++)
    {
        int A,B,C;
        A=i;
        B=place[A];
        C=place[B];
        if(A==place[C])
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
/**
**/