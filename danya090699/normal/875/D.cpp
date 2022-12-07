#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    long long an=0;
    cin>>n;
    int ar[n];
    int pref[n][30], suf[n][30];
    for(int a=0; a<30; a++)
    {
        pref[0][a]=-1, suf[n-1][a]=n;
    }
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(a+1<n)
        {
            for(int b=0; b<30; b++)
            {
                pref[a+1][b]=pref[a][b];
                if((ar[a]&(1<<b))>0) pref[a+1][b]=a;
            }
        }
    }
    for(int a=n-2; a>=0; a--)
    {
        for(int b=0; b<30; b++)
        {
            suf[a][b]=suf[a+1][b];
            if((ar[a+1]&(1<<b))>0) suf[a][b]=a+1;
        }
    }
    int l[n], r[n];
    stack <int> st;
    for(int a=0; a<n; a++)
    {
        while(st.size()>0)
        {
            if(ar[st.top()]>ar[a]) break;
            else st.pop();
        }
        if(st.size()==0) l[a]=-1;
        else l[a]=st.top();
        st.push(a);
    }
    while(st.size()>0) st.pop();
    for(int a=n-1; a>=0; a--)
    {
        while(st.size()>0)
        {
            if(ar[st.top()]>=ar[a]) break;
            else st.pop();
        }
        if(st.size()==0) r[a]=n;
        else r[a]=st.top();
        st.push(a);
    }
    for(int a=0; a<n; a++)
    {
        long long cu=1ll*(a-l[a])*(r[a]-a);
        int lg=l[a], rg=r[a];
        for(int b=0; b<30; b++)
        {
            if((ar[a]&(1<<b))==0)
            {
                lg=max(lg, pref[a][b]);
                rg=min(rg, suf[a][b]);
            }
        }
        cu-=1ll*(a-lg)*(rg-a);
        an+=cu;
    }
    cout<<an;
}