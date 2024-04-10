#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n%2) cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        int n2=n;
        int an[n+1];
        for(int a=18; a>=0; a--)
        {
            if((1<<a)<=n2)
            {
                for(int b=0; ; b++)
                {
                    if((1<<a)+b>n2)
                    {
                        n2=(1<<a)-b-1;
                        break;
                    }
                    else
                    {
                        an[(1<<a)+b]=(1<<a)-b-1;
                        an[(1<<a)-b-1]=(1<<a)+b;
                    }
                }
            }
        }
        for(int a=1; a<=n; a++) cout<<an[a]<<" ";
        cout<<"\n";
    }
    if(n<6) cout<<"NO";
    else
    {
        if(n==6) cout<<"YES\n3 6 1 5 4 2";
        else
        {
            int an[n+1], ok=1;
            for(int a=3; (1<<a)<=n; a++)
            {
                if(n==(1<<a)) ok=0;
                else
                {
                    an[(1<<a)]=min((1<<(a+1))-1, n);
                    for(int b=(1<<a)+1; b<=min((1<<(a+1))-1, n); b++) an[b]=b-1;
                }
            }
            if(ok)
            {
                cout<<"YES\n3 6 1 7 4 2 5 ";
                for(int a=8; a<=n; a++) cout<<an[a]<<" ";
            }
            else cout<<"NO";
        }
    }
}