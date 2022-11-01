#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<m);};
        auto g=[&](int r,int c)->int{return (in(r,c)?r*m+c:-1);};
        vector<int> to(n*m,-1);
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<m;j++) to[g(i,j)]=g(i+(s[j]=='D')-(s[j]=='U'),j+(s[j]=='R')-(s[j]=='L'));
        }
        vector<int> d(n*m,-1);
        vector<bool> cycle(n*m,0);
        vector<int> st;
        vector<int> vis(n*m,0);
        stack<array<int,2>> s;
        auto go=[&]()
        {
            auto [a,tp]=s.top();
            s.pop();
            int b=to[a];
            if(tp==0)
            {
                if(to[a]==-1)
                {
                    d[a]=1;
                    vis[a]=2;
                    return;
                }
                s.push({a,1});
                vis[a]=1;
                st.push_back(a);
                if(vis[b]==0) s.push({b,0});
                else if(vis[b]==1)
                {
                    int sz=st.size();
                    int idx=sz-1;
                    while(st[idx]!=b) idx--;
                    for(int i=idx;i<sz;i++)                
                    {
                        d[st[i]]=sz-idx;
                        cycle[st[i]]=1;
                    }
                }
            }
            else
            {
                vis[a]=2;
                st.pop_back();
                if(cycle[a]==0) d[a]=d[b]+1;
            }
        };
        auto mv=[&](){while(!s.empty())go();};
        array<int,3> res={-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int id=g(i,j);
                if(vis[id]==0)
                {
                    s.push({id,0});
                    mv();
                }
                res=max(res,{d[id],i+1,j+1});
            }
        }
        cout << res[1] << " " << res[2] << " " << res[0] << "\n";
    }
    return 0;
}