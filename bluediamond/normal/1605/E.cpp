#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int N=(int)2e5+7;
int n,q,init[N],b[N];

struct T {
  ll liber;
  ll coefx;
  ll last;
};

T operator + (T a, T b){
  return {a.liber+b.liber, a.coefx+b.coefx};
}


T operator - (T a, T b){
  return {a.liber-b.liber, a.coefx-b.coefx};
}

T state[N];
ll xs[N];
int inds[N];
ll ln[N];
ll solution[N];

bool cmp(int i,int j){
  return xs[i]<xs[j];
}

bool operator<(T a,T b){return a.last<b.last;}


signed main() {
 // ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n;
  for (int i=1;i<=n;i++)cin>>init[i];
  for (int i=1;i<=n;i++)cin>>b[i];

  cin>>q;
  state[1]={0,1};
  for (int i=2;i<=n;i++){
    state[i]={init[i]-b[i],0};
  }
  for (int i=1;i<=n;i++){
    for (int j=2*i;j<=n;j+=i){
      state[j]=state[j]-state[i];
    }
  }

  for (int i=1;i<=q;i++){
    cin>>xs[i];
    xs[i]=init[1]-xs[i];
    inds[i]=i;
    solution[i]=0;
  }
  sort(inds+1,inds+q+1,cmp);

  vector<T> pozi,negi;
  ll free=0;
  for (int i=1;i<=n;i++){
    if (state[i].coefx==0){
      free+=abs(state[i].liber);
    }else{
      if (state[i].coefx>0)pozi.push_back(state[i]);
      else negi.push_back(state[i]);
    }
  }

  for (auto &it:pozi){
    it.last=-it.liber/it.coefx;
    assert(it.liber+it.coefx*it.last<=0);
    assert(it.liber+it.coefx*(it.last+1)>0);
  }
  for (auto &it:negi){
    ll add=it.liber;
    ll cf=-it.coefx;

   /** add-cf*x<=0
    add<=cf*x
    cf*x<=add-1
    x<=(add-1)/cf**/

    ll x=(add-1)/cf;

    assert(add-cf*x>0);
    assert(add-cf*(x+1)<=0);

    it.last=x;

  }

  int p1=0,p2=0;

  sort(pozi.rbegin(),pozi.rend());
  sort(negi.rbegin(),negi.rend());

  ll t1=0,t2=0,t3=0,t4=0,c1=0,c2=0,c3=0,c4=0;
  for (auto &it:pozi)t1+=it.liber,t2+=it.coefx;
  for (auto &it:negi)t3+=it.liber,t4+=it.coefx;

  for (int j=q;j>=1;j--){
    int ind=inds[j];

    while (p1<pozi.size()&&xs[ind]<=pozi[p1].last) c1+=pozi[p1].liber,c2+=pozi[p1].coefx,p1++;
    while (p2<negi.size()&&xs[ind]<=negi[p2].last) c3+=negi[p2].liber,c4+=negi[p2].coefx,p2++;

    solution[ind]-=(c1+xs[ind]*c2);
    solution[ind]+=((t1-c1)+xs[ind]*(t2-c2));

    solution[ind]+=(c3+xs[ind]*c4);
    solution[ind]-=((t3-c3)+xs[ind]*(t4-c4));
  }

  for (int i=1;i<=q;i++){
    cout<<free+solution[i]<<"\n";
  }

  return 0;
}