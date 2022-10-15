#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> d;

ll sqr(ll x){
  return x*x;
}

ll evaluate_cost(ll x,ll split){
  if(x%split==0){
    assert((x/split)*split==x);
    return sqr(x/split)*split;
  }else{
    assert((x/split)*(split-x%split)+(x/split+1)*(x%split)==x);
    return sqr(x/split)*(split-x%split)+sqr(x/split+1)*(x%split);
  }
}

ll evaluate_derivative(ll x,ll split){
  return evaluate_cost(x,split)-evaluate_cost(x,split+1);
}

pair<ll, ll> get(ll mn) {
  /// while all derivatives are >= mn
  ll cost=0;
  ll cnt=0;
  for(auto&x:d){
    ll l=1,r=x,sol=0;
    while(l<=r){
      ll m=(l+r)/2;
      if(evaluate_derivative(x,m)>=mn){
        sol=m;
        l=m+1; /// swap 1, a
      }else{
        r=m-1; /// swap 1, b
      }
    }
    cost+=evaluate_cost(x,sol+1);
    cnt+=sol;
  }
  return {cost, cnt};
}

const ll INF=(ll)1e18;

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input.txt", "r", stdin);
 /// freopen ("output.txt", "w", stdout);

  {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&x:a) cin>>x;
    d.push_back(a[0]);
    for(int i=1;i<n;i++) d.push_back(a[i]-a[i-1]);
    sort(d.begin(),d.end());
  }


  ll want;
  cin>>want;

  int n=(int)d.size();

  ll l=0,r=INF,sol=-1;


  while(l<=r){
    ll m=(l+r)/2;
    auto it=get(m);
    if(it.first<=want){
      sol=m;
      l=m+1; /// swap 2, a
    }else{
      r=m-1; /// swap 2, b

    }
  }
  if(sol==INF){
    cout<<0;
    return 0;
  }

  ll c=get(sol+1).second;
  ll h=get(sol+1).first;
  assert(h>want);
 // sol++;
  c+=(h-want+sol-1)/sol;
  cout<<c<<"\n";

//  cout<<(h-want)<<" vs "<<sol<<"\n";
  exit(0);
  for(int i=1;i<=10;i++){
    cout<<get(i).first<<" "<<get(i).second<<"\n";
  }


  return 0;
}