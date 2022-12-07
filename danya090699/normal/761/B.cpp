//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, pos=0;
    cin>>n>>l;
    int ar[n], ar2[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int b=0; b<n; b++) cin>>ar2[b];
    for(int a=0; a<n; a++)
    {
        bool ok=1;
        for(int b=0; b<n-1; b++)
        {
            int n1=(a+b)%n, n2=(a+b+1)%n;
            int di=ar2[n2]-ar2[n1];
            if(ar2[n2]<ar2[n1]) di+=l;
            if(di!=ar[b+1]-ar[b]) ok=0;
        }
        if(ok) pos=1;
    }
    if(pos) cout<<"YES";
    else cout<<"NO";
}