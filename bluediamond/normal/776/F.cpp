#include <bits/stdc++.h>

using namespace std;

bool home = 1;
bool ok;

///#define int ll

typedef long long ll;
typedef long double ld;

const int N=100000+7;
int n;
int m;
bool f[N],s[N];
int cox,idu[N];

vector<pair<vector<int>,int>>all;
vector<pair<int,int>>bars;

void addEdge(int a,int b){
  bars.push_back({a,b});
}


vector<int>g[N];
int what[N];
bool vis[N];
int sub[N];

void build(int a,int p=-1){
  sub[a]=1;
  for (auto &b:g[a]){
    if(vis[b]||b==p)continue;
    build(b,a);
    sub[a]+=sub[b];
  }
}

int total;

int fcen(int a,int p=-1){
  int mx=total-sub[a];
  for (auto &b:g[a]){
    if(vis[b]||b==p)continue;
    mx=max(mx,sub[b]);
  }
  if(mx<=total/2)return a;
  for (auto &b:g[a]){
    if(vis[b]||b==p)continue;
    if(mx==sub[b])return fcen(b,a);
  }
  assert(0);
}

void dfs(int a,int dep=1){
  build(a);
  total=sub[a];
  a=fcen(a);
  what[a]=dep;
  vis[a]=1;
  for (auto &b:g[a]){
    if(!vis[b])dfs(b,dep+1);
  }
}

void ins(vector<int>&v,int x){
  v.push_back(x);
  int p=(int)v.size()-1;
  while(p&&v[p-1]>v[p]){
    swap(v[p],v[p-1]);
    p--;
  }
}

int pref[N];
vector<pair<int,int>>gg[N];
bool used[N];
int lt[N],tt,nxt[N];

bool cmp(pair<int,int>a,pair<int,int>b){
  int x=a.second-a.first;
  int y=b.second-b.first;
  x=min(x,n-x);
  y=min(y,n-y);
  return x<y;
}

int aib[N];

void add(int i,int x){
  while(i<=n)aib[i]+=x,i+=i&(-i);
}

int ant[N];

int pre(int i){
  int sol=0;
  while(i)sol+=aib[i],i-=i&(-i);
  return sol;
}

signed main() {
 // ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  vector<pair<int,int>>e;
  cin>>n>>m;

  for (int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    add(a,1);
    add(b,1);
    e.push_back({a,b});
  }
  function<void(int,int)>adde=[&](int i,int j){
    nxt[i]=j;
    ant[j]=i;
  };
  for (int i=1;i<=n;i++)adde(i,i+1);
  adde(n,1);

  sort(e.begin(),e.end(),cmp);
  for (auto &it:e){
    int a=it.first,b=it.second;
    //cout<<"aici:"<<a<<" "<<b<<"\n";
    add(a,-1);
    add(b,-1);
    vector<int>cur;
    if(pre(a)!=pre(b-1))swap(a,b);
    int bef=a;
    while(a!=b){
      cur.push_back(a);
      a=nxt[a];
    }
    cur.push_back(b);
    a=bef;
    adde(a,b);
    /**cout<<"shiba : ";
    for (auto &x:cur){
      cout<<x<<" ";
    }
    cout<<"\n";**/
    sort(cur.rbegin(),cur.rend());
    all.push_back({cur,(int)all.size()+1});
  }
  {

    int a=!e.empty()?e.back().first:1,b=a;
    vector<int>cur={a};

    a=nxt[a];
    while(a!=b){
      cur.push_back(a);
      a=nxt[a];
    }
    sort(cur.rbegin(),cur.rend());

    all.push_back({cur,(int)all.size()+1});
  }
  for (auto &v:all){
    continue;cout<<" : ";
    for (auto &x:v.first){
      cout<<x<<" ";
    }
    cout<<"\n";
  }




  map<pair<int,int>,vector<int>>who;
  for (auto &v:all){
    v.first.push_back(v.first[0]);
    for (int j=0;j<(int)v.first.size()-1;j++){
      int a=v.first[j],b=v.first[j+1];
      if(a>b)swap(a,b);
      who[{a,b}].push_back(v.second);
    }
    v.first.pop_back();
  }
  for (auto &it:who){
    assert((int)it.second.size()==1||(int)it.second.size()==2);

    if((int)it.second.size()==2){
      addEdge(it.second[0],it.second[1]);
    }
  }




  sort(all.rbegin(),all.rend());

  for (auto &v:all){
    continue;
   int su=0;
    //cout<<" ---> ";
    for (auto &x:v.first){
    //  cout<<x<< " ";
      su+=(1<<x);
    }
  //  cout<<" : "<<su<<"\n";
  }
  reverse(all.begin(),all.end());



  {
    map<int,int>wnow;
    int foo=0;
    for (auto &v:all){
      wnow[v.second]=++foo;
    }
    for (auto &it:bars){
      it.first=wnow[it.first];
      it.second=wnow[it.second];
      g[it.first].push_back(it.second); swap(it.first,it.second);
      g[it.first].push_back(it.second);
    }
  }


  dfs(1);
 // shiba(nodes);


  ///rofl(0,(int)shiba.size()-1);
  for (int i=1;i<=m+1;i++){
    cout<<what[i]<<" ";
  }
  cout<<"\n";

  return 0;

  for (auto &v:all){
    cout<<" ---> ";
    for (auto &x:v.first){
      cout<<x<< " ";
    }
    cout<<"\n";
  }


  for (auto &it:bars){
    cout<<"lol:"<<it.first<<" "<<it.second<<"\n";
  }


  return 0;
}