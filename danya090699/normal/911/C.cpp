#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int ar[3];
    cin>>ar[0]>>ar[1]>>ar[2];
    sort(ar, ar+3);
    if(ar[0]==1) cout<<"YES";
    else if(ar[0]==2)
    {
        if(ar[1]==2) cout<<"YES";
        else
        {
            if(ar[1]==4 and ar[2]==4) cout<<"YES";
            else cout<<"NO";
        }
    }
    else if(ar[0]==3)
    {
        if(ar[1]==3 and ar[2]==3) cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"NO";
}