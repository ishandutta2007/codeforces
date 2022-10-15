#include <bits/stdc++.h>

using namespace std;

struct T{
  int k;
  int d;
};

vector<int> combine_transposition(vector<int> a, vector<int> b) {
  int n=(int)a.size();
  assert((int)a.size()==n);
  assert((int)b.size()==n);
  vector<int> c(n);
  for (int i=0;i<n;i++) {
    /// i->a[i]->b[a[i]]
    c[i]=b[a[i]];
  }
  return c;
}

vector<int> apply_transposition(vector<int> a, vector<int> transposition) {
  int n=(int)a.size();
  assert((int)a.size()==n);
  assert((int)transposition.size()==n);
  vector<int> b(n);
  for (int i=0;i<n;i++){
    b[transposition[i]]=a[i];
  }
  return b;
}

vector<int> get_transposition(int n, int by) {
  by%=n;
  if(by<0) by+=n;
  vector<int> transposition(n);
  for(int i=0;i<n;i++){
    transposition[i]=(i+by)%n;
  }
  return transposition;
}

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  string init_str;
  cin>>init_str;
  int n=(int)init_str.size(),m;
  cin>>m;
  assert(n<=(int)1e6/m);
  vector<T> v(m);
  for (int i=0;i<m;i++){
    cin>>v[i].k>>v[i].d;
  }

  vector<int> p(n);
  iota(p.begin(),p.end(),0);

  for (int i=0;i<m;i++) {
    int done=0;
    vector<int> transposition(n);
    iota(transposition.begin(),transposition.end(),0);
    vector<vector<int>> inds(v[i].d);
    for (int j=0;j<v[i].k;j++){
      inds[j%v[i].d].push_back(j);
    }
    int pz=0;
    for (int j=0;j<v[i].d;j++) {
      for (auto &i:inds[j]) {
        transposition[i]=pz++;
      }
    }
    transposition=combine_transposition(transposition,get_transposition(n,-1));
    vector<int> ret(n);
    iota(ret.begin(),ret.end(),0);
    done=n-v[i].k+1;

    while(done){
      if(done&1){
        ret=combine_transposition(ret,transposition);
      }
      transposition=combine_transposition(transposition,transposition);
      done/=2;
    }
    done=n-v[i].k+1;
    p=apply_transposition(p,ret);
    p=apply_transposition(p,get_transposition(n,+done));
    assert((int)p.size()==n);
    for (int i=0;i<n;i++){
      assert(0<=p[i]&&p[i]<n);
      cout<<init_str[p[i]];
    }
    cout<<"\n";
  }

}