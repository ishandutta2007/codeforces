/*
    I found myself in Wonderland
    Get back on my feet again..
*/

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
#define pb push_back

#define Query pair<pair<int , int> , pair<int , int>>
#define left first.first
#define right first.second

const int max_n = 1e5 + 30;
const int SQRT = 330;

int n , q , t;
vector<int> adj[max_n];
vector<int> col(max_n) , vec(max_n);
int st[max_n], ft[max_n], cnt[max_n] , fen[max_n];
bool mark[max_n];
vector<int> ans(max_n);
vector<Query>	  query;

void dfs(int v){
    if (mark[v])    return;
    vec[t] = col[v];
    st[v] = t, t++;
    mark[v] = 1;
    for (int i = 0 ; i < adj[v].size() ; i++)   
	 dfs(adj[v][i]);
    ft[v] = t;
}

bool help(Query a , Query b){
    if (a.left / SQRT < b.left / SQRT)  return  true;
    if (a.left / SQRT > b.left / SQRT)  return  false;
    return  a.right < b.right;
}

int get(int p){
    int ret = 0;
    for (;p > 0 ; p -= p& -p)
	 ret += fen[p];
    return  ret;
}

void modify(int p , int val){
    for (p++; p < max_n ; p+= p& -p)
	 fen[p] += val;
}

void add(int ind){
    modify(cnt[vec[ind]] , -1);
    cnt[vec[ind]]++;
    modify(cnt[vec[ind]] , 1);
}

void erase(int ind){
    modify(cnt[vec[ind]] , -1);
    cnt[vec[ind]]--;
    modify(cnt[vec[ind]] , 1);
}

int main(){
    scanf("%d%d" , &n , &q);
    for (int i = 0 ; i < n ; i++)
	 scanf("%d" , &col[i]);
    for (int i = 0 ; i < n - 1 ; i++){
	 int a , b;  scanf("%d%d" , &a , &b);    a--, b--;
	 adj[a].pb(b);
	 adj[b].pb(a);
    }	 
    dfs(0);
    
    modify(0 , n);
    for (int i = 0 ; i < q ; i++){
	 int v, k, l, r;	scanf("%d%d" , &v , &k);	v--;
	 l = st[v], r = ft[v];
	 query.push_back({{l , r} , {i , k}});
    }	 
    sort(query.begin() , query.end() , help);
    
    int l = 0, r = 0;
    for (int i = 0 ; i < q ; i++){
	 int ql = query[i].left , qr = query[i].right , qk = query[i].second.second;
	 while (r < qr)  add(r), r++;
	 while (l > ql)  l--, add(l);
	 while (r > qr)  r--, erase(r);
	 while (l < ql)  erase(l), l++;
	 ans[query[i].second.first] = get(max_n) - get(qk);
    }
    
    for (int i = 0 ; i < q ; i++)
	 printf("%d\n" , ans[i]);
    return 0;
}