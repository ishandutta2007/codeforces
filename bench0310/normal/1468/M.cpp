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
        vector<int> v[n+1];
        int m=0;
        map<int,int> cc;
        for(int i=1;i<=n;i++)
        {
            int c;
            cin >> c;
            m+=c;
            v[i].assign(c,0);
            for(int j=0;j<c;j++)
            {
                cin >> v[i][j];
                if(cc.find(v[i][j])!=cc.end()) v[i][j]=cc[v[i][j]];
                else v[i][j]=cc[v[i][j]]=cc.size();
            }
        }
        array<int,2> res={-1,-1};
        const int sz=sqrt(m);
        const int lim=m/sz; //max number of big sets
        vector<vector<bool>> sets(lim,vector<bool>(m,0));
        int id=0;
        vector<int> big_id(n+1,-1);
        vector<int> rev_id(lim,-1);
        vector<bool> is_big(n+1,0);
        vector<int> occ[m];
        for(int i=1;i<=n;i++)
        {
            if((int)v[i].size()<sz) continue;
            is_big[i]=1;
            big_id[i]=id++;
            rev_id[big_id[i]]=i;
            for(int a:v[i])
            {
                sets[big_id[i]][a]=1;
                occ[a].push_back(i);
            }
        }
        vector<vector<int>> cnt(lim,vector<int>(lim,0));
        for(int i=0;i<m;i++) for(int a:occ[i]) for(int b:occ[i]) cnt[big_id[a]][big_id[b]]++;
        for(int i=0;i<lim;i++) for(int j=i+1;j<lim;j++) if(cnt[i][j]>=2) res={rev_id[i],rev_id[j]};
        for(int i=1;i<=n;i++)
        {
            if(is_big[i]) continue;
            for(int j=0;j<id;j++)
            {
                int c=0;
                for(int a:v[i]) c+=(sets[j][a]);
                if(c>=2) res={i,rev_id[j]};
            }
        }
        vector<array<int,2>> val[m];
        for(int i=1;i<=n;i++)
        {
            if(is_big[i]) continue;
            for(int a:v[i]) for(int b:v[i]) if(a<b) val[a].push_back({b,i});
        }
        vector<int> now(m,0);
        for(int i=0;i<m;i++)
        {
            for(auto [a,x]:val[i])
            {
                if(now[a]==0) now[a]=x;
                else res={now[a],x};
            }
            for(int j=0;j<(int)val[i].size();j++) now[val[i][j][0]]=0;
        }
        if(res[0]!=-1) cout << res[0] << " " << res[1] << "\n";
        else cout << "-1\n";
    }
    return 0;
}