#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=1; a<n-1; a++)
    {
        if((ar[a-1]<ar[a] and ar[a+1]<ar[a]) or (ar[a-1]>ar[a] and ar[a+1]>ar[a])) q++;
    }
    cout<<q;
}