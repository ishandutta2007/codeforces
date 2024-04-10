#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n==1) cout<<"YES\n1 1000000000";
    else
    {
        int ar[n], x=1, y=1, ok=1;
        for(int a=0; a<n; a++)
        {
            cin>>ar[a];
            ar[a]--;
        }
        for(int a=1; a<n; a++) if(abs(ar[a]-ar[a-1])>1) y=abs(ar[a]-ar[a-1]);
        for(int a=1; a<n; a++)
        {
            int d=abs(ar[a]-ar[a-1]);
            if(d!=y)
            {
                if(d==1)
                {
                    if(ar[a]/y!=ar[a-1]/y) ok=0;
                }
                else ok=0;
            }
            x=max(x, ar[a]/y+1);
            x=max(x, ar[a-1]/y+1);
        }
        if(ok) cout<<"YES\n"<<x<<" "<<y;
        else cout<<"NO";
    }
}