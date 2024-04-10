#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q[10], us[10];
    for(int a=0; a<10; a++)
    {
        q[a]=0, us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int st=1;
        us[s[0]-'a']=1;
        for(int b=s.size()-1; b>=0; b--)
        {
            q[s[b]-'a']+=st, st*=10;
        }
    }
    int be=-1, an=0;
    for(int a=0; a<10; a++)
    {
        if(us[a]==0)
        {
            if(be==-1) be=a;
            else if(q[be]<q[a]) be=a;
        }
    }
    q[be]=2e9;
    sort(q, q+10, greater <int>());
    for(int a=0; a<10; a++) an+=a*q[a];
    cout<<an;
}