#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/exception.hpp>
#include<ext/pb_ds/list_update_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N=220000;
gp_hash_table<int,int> *cnt[N];
tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> *tree2[N];
vector<int> edge[N];
array<int,N> ans;
array<bool,N> vis;
list<pair<int,int> > query[N];
int L=0;
void merge(int a,int b)
{
    int k=a;
    if(cnt[a]->size()<cnt[b]->size())
        swap(a,b);
        for(auto &s:*cnt[b])
        {
            if(cnt[a]->find(s.first)==cnt[a]->end())
            {
                tree2[a]->insert({-s.second,++L});
                (*cnt[a])[s.first]=s.second;
            }
            else
            {
                auto it=tree2[a]->lower_bound({-(*cnt[a])[s.first]+1,0});
                --it;
                tree2[a]->erase(it);
                (*cnt[a])[s.first]+=s.second;
                tree2[a]->insert({-(*cnt[a])[s.first],++L});
            }
        }
    tree2[b]->clear(),cnt[b]->clear();
    if(k==b)
        cnt[k]=cnt[a],tree2[k]=tree2[a];
}
void dfs(int a)
{
    vis[a]=true;
    for(auto &s:edge[a])
        if(vis[s]==false)
        {
            dfs(s);
            merge(a,s);
        }
    while(!query[a].empty())
        {
            ans[query[a].front().second]=tree2[a]->order_of_key({-query[a].front().first+1,0});
            query[a].pop_front();
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,u,v,q,k;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cnt[i]=new gp_hash_table<int,int>();
        tree2[i]=new tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>();
        cin>>k;
        (*cnt[i])[k]=1;
        tree2[i]->insert({-1,++L});
    }
    for(int i=0;i<n-1;++i)
        {
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    for(int i=1;i<=q;++i)
    {
        cin>>u>>v;
        query[u].push_back({v,i});
    }
    dfs(1);
    for(int i=1;i<=q;++i)
        cout<<ans[i]<<'\n';
    return 0;
}