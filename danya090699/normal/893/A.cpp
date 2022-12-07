#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p1=1, p2=2, p3=3, ok=1;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(x!=p1) swap(p1, p2);
        if(x!=p1)
        {
            ok=0;
            break;
        }
        swap(p2, p3);
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}