#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
bitset <sz> s[26], an;
int main()
{
    //freopen("input.txt", "r", stdin);
    string ss;
    cin>>ss;
    int n=ss.size(), q;
    for(int a=0; a<n; a++) s[ss[a]-'a'][a]=1;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int p;
            char sy;
            scanf("%d", &p);
            p--;
            cin>>sy;
            for(int b=0; b<26; b++)
            {
                if(sy-'a'==b) s[b][p]=1;
                else s[b][p]=0;
            }
        }
        else
        {
            int l, r;
            string s2;
            scanf("%d%d", &l, &r);
            l--;
            cin>>s2;
            int m=s2.size();
            an.set();
            for(int b=0; b<m; b++) an&=(s[s2[b]-'a']>>b);
            an>>=l;
            an<<=l;
            an<<=(sz-r+(m-1));
            printf("%d\n", an.count());
        }
    }
}