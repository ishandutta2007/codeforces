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
        int n;
        cin >> n;
        vector a(2*n+1,vector(n+1,int(0))); //all zeroed out if already used
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=n;j++) cin >> a[i][j];
        }
        vector intersect(2*n+1,vector(2*n+1,bool(0)));
        for(int i=1;i<=2*n;i++)
        {
            for(int j=i+1;j<=2*n;j++)
            {
                bool b=0;
                for(int k=1;k<=n;k++) b|=(a[i][k]==a[j][k]);
                intersect[i][j]=intersect[j][i]=b;
            }
            intersect[i][i]=1;
        }
        vector<int> forced;
        //add forced ones, remove their adjacent arrays
        for(int o=1;o<=n;o++)
        {
            bool found=0;
            for(int j=1;j<=n;j++)
            {
                vector<int> c(n+1,0);
                for(int i=1;i<=2*n;i++) c[a[i][j]]++;
                for(int x=1;x<=n;x++)
                {
                    if(c[x]!=1) continue;
                    //found forced array
                    int id=0;
                    for(int i=1;i<=2*n;i++) if(a[i][j]==x) id=i;
                    forced.push_back(id);
                    for(int i=1;i<=2*n;i++)
                    {
                        if(intersect[id][i]&&a[i][1]!=0)
                        {
                            for(int k=1;k<=n;k++) a[i][k]=0;
                        }
                    }
                    found=1;
                    break;
                }
                if(found) break;
            }
            if(!found) break;
        }
        vector<int> nodes;
        vector<int> v[2*n+1];
        for(int i=1;i<=2*n;i++)
        {
            if(a[i][1]==0) continue;
            nodes.push_back(i);
            for(int j=i+1;j<=2*n;j++)
            {
                if(a[j][1]==0) continue;
                if(intersect[i][j])
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        ll res=1;
        const ll mod=998244353;
        vector<int> col(2*n+1,-1);
        vector<int> opt=forced;
        for(int i:nodes)
        {
            if(col[i]!=-1) continue;
            vector<int> q={i};
            col[i]=0;
            int idx=0;
            while(idx<(int)q.size())
            {
                int b=q[idx++];
                for(int to:v[b])
                {
                    if(col[to]==-1)
                    {
                        col[to]=(col[b]^1);
                        q.push_back(to);
                    }
                }
            }
            for(int b:q) if(col[b]==0) opt.push_back(b);
            res=(2*res)%mod;
        }
        cout << res << "\n";
        for(int i=0;i<n;i++) cout << opt[i] << " \n"[i==n-1];
    }
    return 0;
}