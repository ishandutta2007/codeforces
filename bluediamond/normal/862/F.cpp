#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int N=(int)1e5+7;
const int K=100;
int n,q,lcp[N],treemax1[4*N];
string s[N];

struct node{
  int sol[K];
  int pre[K];
  int suf[K];
};

node tree[4*N];

node join(node a,node b,int la,int ra,int lb,int rb){
  for (int l=1;l<K;l++){
    int __sol=max(a.suf[l]+b.pre[l],max(a.sol[l],b.sol[l]));
    int __pre=a.pre[l]+b.pre[l]*(a.pre[l]==ra-la+1);
    int __suf=b.suf[l]+a.suf[l]*(b.suf[l]==rb-lb+1);

    a.sol[l]=__sol;
    a.pre[l]=__pre;
    a.suf[l]=__suf;
  }
  return a;
}

void upd(int v,int tl,int tr,int i){
  if (tl==tr){
    for (int l=1;l<K;l++){
      tree[v].sol[l]=tree[v].pre[l]=tree[v].suf[l]=(lcp[tl]>=l);
    }
    return;
  }
  int tm=(tl+tr)/2;
  if (i<=tm)upd(2*v,tl,tm,i);
  else upd(2*v+1,tm+1,tr,i);
  tree[v]=join(tree[2*v],tree[2*v+1],tl,tm,tm+1,tr);
}

node get(int v,int tl,int tr,int l,int r){
  if(l<=tl&&tr<=r)return tree[v];
  int tm=(tl+tr)/2;
  if(r<=tm)return get(2*v,tl,tm,l,r);
  if(tm+1<=l) return get(2*v+1,tm+1,tr,l,r);
  return join(get(2*v,tl,tm,l,r),get(2*v+1,tm+1,tr,l,r),max(tl,l),tm,tm+1,min(r,tr));
}

void upd1(int v,int tl,int tr,int i,int val){
  if(tr<i||i<tl)return;
  if(tl==tr){
    treemax1[v]=val;
  }else{
    int tm=(tl+tr)/2;
    upd1(2*v,tl,tm,i,val);
    upd1(2*v+1,tm+1,tr,i,val);
    treemax1[v]=max(treemax1[2*v],treemax1[2*v+1]);
  }
}

int get1(int v,int tl,int tr,int l,int r){
  if(tr<l||r<tl)return 0;
  if(l<=tl&&tr<=r)return treemax1[v];
  int tm=(tl+tr)/2;
  return max(get1(2*v,tl,tm,l,r),get1(2*v+1,tm+1,tr,l,r));
}

vector<int> del(vector<int> v,int val){
  int f=0;
  vector<int>sol;
  for (auto &x:v){
    if (x!=val)sol.push_back(x);
    else f++;
  }


  return sol;
}

vector<int> add(vector<int> v, int val){
  vector<int>sol;
  int p=0;
  while (p<v.size()&&v[p]<val) sol.push_back(v[p++]);

  sol.push_back(val);

  while (p<v.size())sol.push_back(v[p++]);
  return sol;
}

vector<int> giants;


void compute(int i){
  bool inside=(1<=i&&i<n);
  if(!inside)return;
  /// i,i+1



  if (lcp[i]>=K){
    giants=del(giants,i);
  }

  lcp[i]=0;

  while (lcp[i]<min((int)s[i].size(),(int)s[i+1].size())&&s[i][lcp[i]]==s[i+1][lcp[i]])lcp[i]++;

  if (lcp[i]>=K){

    giants=add(giants,i);
  }
  upd(1,1,n,i);
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /**
  int x;
  cout<<sizeof(x)<<"\n";
  set<int> st;
  cout<<sizeof(st)<<"\n";
  for (int i=1;i<=10;i++){
    st.insert(i);
  }
  cout<<sizeof(st)<<"\n";

  return 0;
**/


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin>>n>>q;

  for (int i=1;i<=n;i++){
    cin>>s[i];
    upd1(1,1,n,i,s[i].size());
  }




  for (int i=1;i<n;i++) compute(i);




  for (int iq=1;iq<=q;iq++) {
    int tp;
    cin>>tp;

    if(tp==1){
      int x,y;
      cin>>x>>y;
      y--;
      ll sol=get1(1,1,n,x,y+1);


      if(x<=y){
        auto best=get(1,1,n,x,y);
        for (int len=1;len<K;len++){

          best.sol[len]+=(best.sol[len]>0);
          sol=max(sol,(ll)best.sol[len]*len);
        }
      }


/**      for (int l=x;l<=y;l++){
        int cur=s[l].size();
        for (int r=l;r<=y;r++){
          cur=min(cur,lcp[r]);
          if(cur>=K){
            sol=max(sol,(ll)cur*(r-l+2));
          }
        }
      }**/
      vector<vector<int>> all;

      int ant=-1;

      for (auto &i:giants){

        if(x<=i&&i<=y){
          if(all.empty()||i!=ant+1)all.push_back({lcp[i]});
          else all.back().push_back(lcp[i]);
        }
        ant=i;
      }


      for (auto &ve:all){
        vector<int>stk,l(ve.size()),r(ve.size());
        for (int i=0;i<ve.size();i++){
          while (!stk.empty()&&ve[i]<=ve[stk.back()]) stk.pop_back();
          if (stk.empty())l[i]=0;
          else l[i]=stk.back()+1;
          stk.push_back(i);
        }
        stk.clear();
        for (int i=ve.size()-1;i>=0;i--){
          while (!stk.empty()&&ve[i]<=ve[stk.back()]) stk.pop_back();
          if (stk.empty())r[i]=ve.size()-1;
          else r[i]=stk.back()-1;
          stk.push_back(i);
        }
        for (int j=0;j<ve.size();j++){
          sol=max(sol,(ll)ve[j]*(r[j]-l[j]+2));
        }

      }
      cout<<sol<<"\n";
    }else{
      int i;
      cin>>i;
      cin>>s[i];
      compute(i-1);
      compute(i);
      upd1(1,1,n,i,s[i].size());
    }
  }

  return 0;
}