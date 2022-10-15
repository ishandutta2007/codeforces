#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int N=(int)1e5+7;
const int M=2*333;
int n,q,p[N],limit[N],l[N],r[N],top,nod[N];
vector<int> g[N];
const int LG=19;
int vac[N], cur[N], aici[N], curp[N], top2, dep[N], lg[2*N], ff[N], ss[N], ant;
pair<int,int> tab[LG][2*N];
int nowpar[N];

void build(int a){
  l[a]=++top;
  tab[0][++top2]={dep[a],a};
  ff[a]=ss[a]=top2;
  nod[top]=a;
  for (auto &b:g[a]){
    dep[b]=1+dep[a];
    build(b);
    tab[0][++top2]={dep[a],a};
    ss[a]=top2;
  }
  r[a]=top;
}

int lca(int a, int b){
  if (ff[a]>ss[b]) swap(a,b);
  a=ff[a];
  b=ss[b];
  assert(a<=b);
  int k=lg[b-a+1];
  return min(tab[k][a],tab[k][b-(1<<k)+1]).second;
}

int init[N];
bool bl[N];
int pz[N];

vector<int> la[3*N];
int jambala[N],cop[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int nax;
  cin>>n>>q;
  nax=max(n,q);
  for (int i=2;i<=n;i++){
    cin>>p[i];
    g[p[i]].push_back(i);
  }
  for (int i=1;i<=n;i++){
    cin>>limit[i];
    cur[i]=limit[i];
    aici[i]=1;
  }
  build(1);
  for (int i=2;i<=top2;i++)lg[i]=1+lg[i/2];
  for (int k=1;(1<<k)<=top2;k++){
    for (int i=1;i+(1<<k)-1<=top2;i++){
      tab[k][i]=min(tab[k-1][i],tab[k-1][i+(1<<(k-1))]);
    }
  }
  int cl=0;
  int liq=1,steps=0;
  while (liq<=q){
    steps++;
    int riq=min(q,liq+M-1);
    vector<int> order(riq-liq+1);
    liq=riq+1;
    for (auto &x:order){
      cin>>x;
      x=abs(x);
    }
    vector<pair<int,int>> sorder;
    for (auto &x:order){
      sorder.push_back({l[x],x});
    }
    sort(sorder.begin(),sorder.end());
    vector<pair<int,int>>nodes=sorder;
    for (int i=0;i<(int)sorder.size()-1;i++){
      int v=lca(sorder[i].second,sorder[i+1].second);
      nodes.push_back({l[v],v});
    }
    nodes.push_back({l[1],1});
    sort(nodes.begin(),nodes.end());
    vector<int> allnodes;
    for (auto &it:nodes){
      if (allnodes.empty()||allnodes.back()!=it.second)allnodes.push_back(it.second);
    }
    for (int i=0;i<=3*nax;i++){
      la[i].clear();
    }
    vector<int> stk;
    for (auto &kwk:nodes){
      int a=kwk.second;
      while (!stk.empty()&&!(l[stk.back()]<l[a]&&r[a]<=r[stk.back()]))stk.pop_back();
      if (!stk.empty()) nowpar[a]=stk.back();
      stk.push_back(a);
    }
    for (int i=1;i<=n;i++){
      init[i]=cur[i];
      bl[i]=0;
      pz[i]=-1;
      jambala[i]=0;
      cop[i]=cur[i];
    }
    vector<pair<int,vector<int>>> cox, cox3;
    int solution=ant;
    for (auto &i:allnodes){
      vector<int>current;
      int j=p[i];
      while (j!=nowpar[i]){
        current.push_back(j);
        j=p[j];
      }
      vector<int> panamera, lambo;
      for (auto &i:current){
        bl[i]=1;
        if (aici[i])panamera.push_back(i);
        else lambo.push_back(i);
        solution-=(cur[i]<0)*aici[i];
      }
      if (!panamera.empty()){
        cox.push_back({i,panamera});
        for (auto &x:panamera){
          pz[x]=cox.size()-1;
          int value=cur[x]+nax;
          la[value].push_back(x);
        }
      }
      if (!lambo.empty()){
        cox3.push_back({i,lambo});
      }
    }
    vector<pair<int,vector<pair<int,int>>>> cox2(cox.size());
    vector<int> ptr(cox.size(),0);
    int tuctuc=0;
    for (int i=0;i<cox.size();i++){
      cox2[i].first=cox[i].first;
    }
    for (int value=0;value<=3*nax;value++){

      int l=0;
      while (l<la[value].size()){
        int r=l;
        while (r+1<la[value].size()&&pz[la[value][r+1]]==pz[la[value][r]]){
          r++;
        }

        int halo=pz[la[value][r]];
        auto it=make_pair(value-nax,r-l+1);
        auto vec=cox2[halo].second;

        cox2[halo].second.push_back(it);
        l=r+1;
      }

    }
    for (auto &i:order){
      if (vac[i] == 0) {
        /// i se duce in vacanta
        /// daca era suparici, acumici nu mai e
        vac[i]=1;
        aici[i]=0;
        solution-=(cop[i]<0);
        /// sa vedem pe cine a facut el suparici
        int j=i;
        while (j){
          solution+=(cop[j]==0)*aici[j];
          jambala[j]--;
          cop[j]--;
          j=nowpar[j];

        }


      } else {
        /// i se intoarce din vacanta
        /// daca nu era suparici, acumici e
        vac[i]=0;
        aici[i]=1;
        solution+=(cop[i]<0);

        /// sa vedem pe cine face fericici

        int j=i;


        while (j){

          solution-=(cop[j]==-1)*aici[j];
          cop[j]++;
          jambala[j]++;
          j=nowpar[j];
        }

      }
      for (int yandex=0;yandex<cox2.size();yandex++){
        /// try to grow it?
        while (ptr[yandex]<(int)cox2[yandex].second.size() && cox2[yandex].second[ptr[yandex]].first+jambala[cox2[yandex].first]<0){
          tuctuc+=cox2[yandex].second[ptr[yandex]++].second;
        }

        while (ptr[yandex]-1>=0 && cox2[yandex].second[ptr[yandex]-1].first+jambala[cox2[yandex].first]>=0){
          tuctuc-=cox2[yandex].second[--ptr[yandex]].second;
        }
      }
      ant=solution+tuctuc;
      cout<<solution+tuctuc<<" ";

    }
    for (int i=1;i<=n;i++) {
      if (!bl[i]){
        cur[i]=cop[i];
      }
    }
    for (auto &itr:cox){
      for (auto &v:itr.second){
        cur[v]=init[v]+jambala[itr.first];
      }
    }
    for (auto &itr:cox3){
      for (auto &v:itr.second){
        cur[v]=init[v]+jambala[itr.first];
      }
    }
  }

  cout<<"\n";



  return 0;
}