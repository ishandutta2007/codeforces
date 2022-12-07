#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int p0=n, p1=n, an[n+1], go[n+1];
    vector <int> sp[n+1], ch[n+1], st, pos[n+1];
    go[n]=0;
    st.push_back(n);
    for(int a=n-1; a>=0; a--)
    {
        if(s[a]=='0') p0=a;
        if(s[a]=='1') p1=a;
        go[a]=max(p0, p1)-a;
        while(st.size() and go[st.back()]<=go[a])
        {
            ch[a].push_back(st.back());
            st.pop_back();
        }
        st.push_back(a);

        //cout<<go[a]<<" ";
    }
    for(int a=1; a<=n; a++)
    {
        pos[0].push_back(a);
        an[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        /*for(int b=0; b<st.size(); b++)
        {
            cout<<st[b]<<" ";
        }
        cout<<"\n";*/

        while(pos[a].size())
        {
            int len=pos[a].back();

            int l=-1, r=st.size();
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(go[st[mid]]>=len) l=mid;
                else r=mid;
            }
            if(l!=-1) an[len]++, pos[st[l]+len].push_back(len);

            pos[a].pop_back();
        }
        st.pop_back();
        while(ch[a].size())
        {
            st.push_back(ch[a].back());
            ch[a].pop_back();
        }
    }
    for(int a=1; a<=n; a++) printf("%d ", an[a]);
}