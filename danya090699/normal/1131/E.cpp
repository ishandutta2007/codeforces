#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q[26];
    cin>>n;
    for(int a=0; a<26; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int m=s.size();
        int nq[26], l[m];
        for(int a=0; a<26; a++) nq[a]=(q[a]>0);
        int yk=0;
        while(yk<m)
        {
            int st=yk;
            while(yk<m)
            {
                if(s[yk]==s[st]) yk++;
                else break;
            }
            for(int b=st; b<yk; b++) l[b]=yk-st;
            int sy=s[st]-'a';
            nq[sy]=max(nq[sy], yk-st);
        }
        if(l[0]==m)
        {
            int sy=s[0]-'a';
            nq[sy]=min(q[sy]+(q[sy]+1)*m, inf);
        }
        else if(s[0]==s[m-1])
        {
            int sy=s[0]-'a';
            if(q[sy])
            {
                nq[sy]=max(nq[sy], min(l[0]+l[m-1]+1, inf));
            }
        }
        else
        {
            int lsy=s[0]-'a';
            if(q[lsy]) nq[lsy]=max(nq[lsy], min(l[0]+1, inf));

            int rsy=s[m-1]-'a';
            if(q[rsy]) nq[rsy]=max(nq[rsy], min(l[m-1]+1, inf));
        }
        for(int b=0; b<26; b++) q[b]=nq[b];
    }
    int an=0;
    for(int a=0; a<26; a++) an=max(an, q[a]);
    cout<<an;
}