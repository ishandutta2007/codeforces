#include <bits/stdc++.h>
using namespace std;
const int inf=(1<<17);
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    if(n==2 and x==0) cout<<"NO";
    else
    {
        cout<<"YES\n";
        if(n==1) cout<<x;
        else if(n==2) cout<<0<<" "<<x;
        else
        {
            int cu=0;
            for(int a=1; a<n-2; a++)
            {
                cout<<a<<" ";
                cu^=a;
            }
            cout<<inf<<" "<<inf*2<<" ";
            cu=cu^inf^(inf*2);
            cout<<(cu^x);
        }
    }

}