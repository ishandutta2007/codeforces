//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ok=1;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=1; a<n-1; a++)
    {
        if(ar[a]<ar[a+1] and ar[a-1]>=ar[a]) ok=0;
        if(ar[a]==ar[a+1] and ar[a-1]>ar[a]) ok=0;
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}