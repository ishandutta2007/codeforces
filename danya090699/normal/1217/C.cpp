#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        string s;
        cin>>s;
        int n=s.size(), pref[n+1], an=0;
        pref[0]=0;
        for(int a=0; a<n; a++)
        {
            int x=0;
            for(int b=a; x+(1<<(a-b))<=a+1; b--)
            {
                if(s[b]=='1')
                {
                    x+=1<<(a-b);
                    if(pref[b]==pref[a+1-x]) an++;
                }
            }
            pref[a+1]=pref[a]+(s[a]=='1');
        }
        cout<<an<<"\n";
    }
}