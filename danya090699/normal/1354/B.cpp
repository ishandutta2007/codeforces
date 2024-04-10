#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int pr[3]={-1, -1, -1}, an=inf;
        string s;
        cin>>s;
        for(int a=0; a<s.size(); a++)
        {
            pr[s[a]-'1']=a;
            int mi=inf;
            for(int i=0; i<3; i++) mi=min(mi, pr[i]);
            if(mi!=-1) an=min(an, a-mi+1);
        }
        if(an==inf) cout<<"0\n";
        else cout<<an<<"\n";
    }
}