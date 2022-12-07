#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int l, r, d;
        cin>>l>>r>>d;
        if(d<l) cout<<d;
        else cout<<(r/d+1)*d;
        cout<<"\n";
    }
}