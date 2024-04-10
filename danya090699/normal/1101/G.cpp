#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int pref[n+1];
    pref[0]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        pref[a+1]=pref[a]^x;
    }
    if(pref[n])
    {
        int mn[30], an=0;
        for(int i=0; i<30; i++) mn[i]=0;
        for(int a=n; a>0; a--)
        {
            int x=pref[a];
            for(int i=29; i>=0; i--)
            {
                if(x&(1<<i))
                {
                    if(mn[i]) x^=mn[i];
                    else
                    {
                        mn[i]=x, an++;
                        break;
                    }
                }
            }
        }
        cout<<an;
    }
    else cout<<-1;
}