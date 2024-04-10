#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n,m,need,have;
vector<int>g[N];

int t[N];

int gt(int a)
{
        if(a==t[a])
        {
                return a;
        }
        else
        {
                t[a]=gt(t[a]);
                return t[a];
        }
}

vector<pair<int,int>>res;

void uni(int a,int b)
{
        res.push_back({a,b});
        a=gt(a);
        b=gt(b);
        if(a!=b)
        {
                t[a]=b;
        }
}

int t2[N];

int gt2(int a)
{
        if(a==t2[a])
        {
                return a;
        }
        else
        {
                t2[a]=gt2(t2[a]);
                return t2[a];
        }
}

void uni2(int a,int b)
{
        a=gt2(a);
        b=gt2(b);
        if(a!=b)
        {
                t2[a]=b;
        }
}

int first[N];

void dfs(int nod,int id)
{
        first[nod]=id;
        for(auto &nou:g[nod])
        {
                if(nou==1) continue;
                if(first[nou]==-1)
                {
                        dfs(nou,id);
                }
                else
                {
                        uni2(first[nod],first[nou]);
                }
        }
}

vector<int>who[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m>>need;
        for(int i=1;i<=n;i++)
        {
                t[i]=i;
                t2[i]=i;
                first[i]=-1;
        }
        for(int i=1;i<=m;i++)
        {
                int a,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        int id=0;
        for(auto &nod:g[1])
        {
                id++;
                if(first[nod]==-1)
                {
                        dfs(nod,id);
                }
                else
                {
                        uni2(first[nod],id);
                }
        }
        id=0;
        for(auto &nod:g[1])
        {
                id++;
                who[gt2(id)].push_back(nod);
            ///    cout<<" : "<<nod<<" : "<<gt2(id)<<"\n";
        }
        for(int i=1;i<=n;i++)
        {
                if(who[i].size()==0) continue;
                have++;
                uni(1,who[i][0]);
        }
      //  cout<<have<<" , "<<res.size()<<"\n";
        for(int i=1;i<=n && have<need;i++)
        {
      //  cout<<have<<" , "<<res.size()<<"\n";
                for(auto &it:who[i])
                {
                        if(gt(1)==gt(it)) continue;
                        if(have==need) break;
                        have++;
                        uni(1,it);
                }
        }
   //     cout<<have<<" , "<<res.size()<<"\n";
        for(int i=2;i<=n;i++)
        {
                for(auto &j:g[i])
                {
                        if(i==1 || j==1) continue;
                        if(gt(i)==gt(j)) continue;
                        uni(i,j);
                }
        }
        have=0;
        if(res.size()!=n-1)
        {
                cout<<"NO\n";
                return 0;
        }
        for(auto &it:res)
        {
                if(it.first==1 || it.second==1)
                {
                        have++;
                }
        }
        for(int i=1;i<=n;i++)
        {
                if(gt(i)!=gt(1))
                {
                        cout<<"NO\n";
                        return 0;
                }
        }
        if(have!=need)
        {
                cout<<"NO\n";
                return 0;
        }
        cout<<"YES\n";
        for(auto &it:res)
        {
                cout<<it.first<<" "<<it.second<<"\n";
        }
        return 0;
}
/**

4 5 3
1 2
1 3
1 4
2 3
3 4


**/