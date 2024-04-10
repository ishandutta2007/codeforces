#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int get(int i,int j){
  cout<<"? "<<i<<" "<<j<<endl;
  int ret;
  cin>>ret;
  assert(ret==0||ret==1||ret==2);
  return ret;
}

int get_bigger(int i,int j){
  int x=get(i,j);

  assert(x!=0);
  if(x==1)return i;
  return j;
}

int solve(vector<int> v) {
  if((int)v.size()==1){
    return v[0];
  }
  if((int)v.size()==2){
    return get_bigger(v[0],v[1]);
  }
  assert((int)v.size()>=4);
  assert((int)v.size()%4==0);
  vector<int> nxt;
  for(int iter=0;iter<(int)v.size();iter+=4){
    assert(iter+3<(int)v.size());
    int a=v[iter],b=v[iter+1],c=v[iter+2],d=v[iter+3];
    int ac=get(a,c);
    if(ac==0){
      nxt.push_back(get_bigger(b,d));
      continue;
    }
    if(ac==2){
      swap(a,c);
      swap(b,d);
      ac=1;
    }
    assert(ac==1);
    /// a>c
    nxt.push_back(get_bigger(a,d));
  }
  assert((int)nxt.size()==(int)v.size()/4);
  return solve(nxt);
}

signed main() {
  ///ios::sync_with_stdio(0); cin.tie(0);

  ///freopen("___input___.txt","r",stdin);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    n=(1<<n);
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    int x=solve(v);
    cout<<"! "<<x<<endl;
  }
}