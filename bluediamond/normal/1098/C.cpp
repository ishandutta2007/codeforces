#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <functional>

using namespace std;

#define int long long

const int N=(int) 1e5+7;
const int INF=(int)1e18+7;
int canat[N],mx[N],deja[N];
vector<int> la[N];

vector<int> get(int n,int s,int limit){
  mx[1]=1;
  for (int i=2;i<=n;i++){
    if(mx[i-1]<=INF/limit){
      mx[i]=mx[i-1]*limit;
    }else{
      mx[i]=INF;
    }
  }
  for (int i=1;i<=n;i++){
    canat[i]=0;
    deja[i]=0;
  }
  la[1].clear();
  for (int i=2;i<=n;i++){
    la[i].clear();
  }
  int ninit=n;
  function<void(int)> consume=[&](int i){
    assert(1<=i&&i<=ninit);
    assert(canat[i]>0);
    assert(n>0);
    assert(s>=i);
    canat[i]--;
    canat[i+1]+=limit;
    deja[i]++;
    n--;
    s-=i;
  };
  function<void(int)> unconsume=[&](int i){
    canat[i]++;
    canat[i+1]-=limit;
    deja[i]--;
    n++;
    s+=i;
  };
  function<int()> getmin=[&](){
    int need=n,sol=0;
    for (int i=1;i<=ninit&&need>0;i++){
      int t=min(need,mx[i]-deja[i]);
      need-=t;
      sol+=t*i;
    }
    assert(need==0);
    return sol;
  };
  canat[1]=1;
  consume(1);
  if(getmin()>s) return {};
  int dep=1;
  la[1].push_back(1);
  int zz=1;
  while(n>0){
    int f=-1;

    for (int i=dep+1;i>=1;i--){
      if(canat[i]&&s>=i){
        consume(i);
        if(getmin()>s){
          unconsume(i);
          continue;
        }
        f=i;
        break;
      }
    }

    if(f==-1){
      return {};
    }
    la[f].push_back(++zz);
    dep=f;
  }
  if(s>0){
    return {};
  }
  n=ninit;
  vector<int> pars(n-1,-100);
  for (int l=2;l<=n;l++){
    int ind=0;
    for (auto &i:la[l]){
      assert(2<=i&&i<=n);
      assert(0<=ind/limit&&ind/limit<(int)la[l-1].size());
      pars[i-2]=la[l-1][ind/limit];
      ind++;
    }
  }
  return pars;
  for (auto &x:pars){
    assert(x!=-100);
  }
  return pars;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	//freopen ("iron_man.txt","r",stdin);

	int n,s;
	cin>>n>>s;

	if(s==n*(n+1)/2){
    cout<<"Yes\n";
    for (int i=1;i<n;i++){
      cout<<i<<" ";
    }
    cout<<"\n";
    exit(0);
	}

	if(get(n,s,n).empty()){
    cout<<"No\n";
    exit(0);
	}
	int l=2,r=n,mn=-1;
	while(l<=r){
    int m=(l+r)/2;
    if(!get(n,s,m).empty()){
      mn=m;
      r=m-1;
    }else{
      l=m+1;
    }
	}
	assert(mn!=-1);

	vector<int> sol=get(n,s,mn);
	cout<<"Yes\n";
  assert((int) sol.size()==n-1);
  for (auto &x:sol){
    cout<<x<<" ";
  }
  cout<<"\n";
}