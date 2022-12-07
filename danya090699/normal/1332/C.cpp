#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, an=0;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int a=0; k-1-a>=a; a++)
        {
            int q[26], su=0, ma=0;
            for(int b=0; b<26; b++) q[b]=0;
            for(int b=0; b<n/k; b++)
            {
                q[s[b*k+a]-'a']++, su++;
                if(a!=k-1-a)
                {
                    q[s[k*(b+1)-1-a]-'a']++, su++;
                }
            }
            for(int b=0; b<26; b++) ma=max(ma, q[b]);
            //cout<<su<<" "<<ma<<"\n";
            an+=su-ma;
        }
        cout<<an<<"\n";
    }
}