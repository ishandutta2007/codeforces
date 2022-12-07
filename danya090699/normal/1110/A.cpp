#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int b, k, st=1, an=0;
    cin>>b>>k;
    int ar[k];
    for(int a=0; a<k; a++) cin>>ar[a];
    reverse(ar, ar+k);
    for(int a=0; a<k; a++)
    {
        int x=ar[a];
        cin>>x;
        an=(an+x*st)%2;
        st=(st*b)%2;
    }
    if(an) cout<<"odd";
    else cout<<"even";
}