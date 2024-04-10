#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(x%4==0) cout<<x/4;
        if(x%4==1)
        {
            if(x==1 or x==5) cout<<-1;
            else cout<<x/4-1;
        }
        if(x%4==2)
        {
            if(x==2) cout<<-1;
            else cout<<x/4;
        }
        if(x%4==3)
        {
            if(x==3 or x==7 or x==11) cout<<-1;
            else cout<<x/4-1;
        }
        cout<<"\n";
    }
}