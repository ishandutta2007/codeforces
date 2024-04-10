#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
}
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
}
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return mul(a,pw(b,M-2));
}
void addup(int &a,int b){
  a=add(a,b);
}
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}

struct modMatrix {
  int n;
  int m;
  int mod;
  vector<vector<int>> a;

  void init(int _n, int _m, int _mod) {
    n = _n;
    m = _m;
    mod = _mod;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(m, 0);
    }
  }
  modMatrix operator * (modMatrix b) {
    if (mod != b.mod) {
      cout << "error the mods do not correspond (when wanting to multiply)\n";
      exit(0);
    }
    if (m != b.n) {
      cout << "error on (mod) matrix sizes (when wanting to multiply)\n";
      exit(0);
    }
    modMatrix c;
    c.init(n, m, mod);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          c.a[i][j] = (c.a[i][j] + (long long) a[i][k] * b.a[k][j]) % mod;
        }
      }
    }
    return c;
  }
  modMatrix operator ^ (long long p) {
    if (n != m) {
      cout << "error on (mod) matrix size (when wanting to rise to the power)\n";
      exit(0);
    }
    modMatrix c, cur;
    c.init(n, m, mod);
    cur.init(n, m, mod);
    cur.a = a;
    for (int i = 0; i < n; i++) {
      c.a[i][i] = 1;
    }
    while (p) {
      if (p & 1) {
        c = c * cur;
      }
      cur = cur * cur;
      p /= 2;
    }
    return c;
  }
};

struct Node{
  Node* kids[26];
  int cnt;

  Node() {
    cnt=0;
    for(int i=0;i<26;i++) {
      kids[i]=0;
    }
  }
};

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n, m;
  cin>>n>>m;
  vector<string> words(n);

  Node* root=new Node;

  for (auto &word:words){
    cin>>word;
    assert(1<=(int) word.size() && (int) word.size()<=5);
    Node* cur=root;
    for (auto &ch:word){
      int x=ch-'a';
      assert(0<=x&&x<26);
      if(!cur->kids[x]) cur->kids[x]=new Node;
      cur=cur->kids[x];
    }
    cur->cnt++;
  }

  set<pair<Node*,Node*>> good_states;

  function<void(Node*, Node*)> expl = [&] (Node* a,Node* b){
    if(a>b) swap(a,b);
    if(good_states.count({a, b}))return;
    good_states.insert({a, b});
    for(int x=0;x<26;x++){
      if(a->kids[x]&&b->kids[x]){
        expl(a->kids[x],b->kids[x]);
      }
    }
    if(a->cnt){
      for (int x=0;x<26;x++){
        if(b->kids[x]&&root->kids[x]){
          expl(root->kids[x],b->kids[x]);
        }
      }
    }
    if(b->cnt){
      for(int x=0;x<26;x++){
        if(a->kids[x]&&root->kids[x]){
          expl(a->kids[x],root->kids[x]);
        }
      }
    }
    if(a->cnt&&b->cnt){
      for (int x=0;x<26;x++) {
        if(root->kids[x]) {
          expl(root->kids[x],root->kids[x]);
        }
      }
    }
  };

  expl(root,root);

  map<pair<Node*,Node*>,int> id;
  for (auto &st:good_states) {id[st]=0;}
  {
    int index=0;
    for (auto &it:id){
      it.second=++index;
    }
    for (auto &it:good_states){
      id[{it.second,it.first}]=id[it];
    }
  }

  vector<pair<int, int>> transitions;
  for (auto &state:good_states){
    Node* a=state.first;
    Node* b=state.second;
    for(int x=0;x<26;x++){
      if(a->kids[x]&&b->kids[x]){
        transitions.push_back({id[state],id[{a->kids[x],b->kids[x]}]});
      }
    }
    if(a->cnt){
      for (int x=0;x<26;x++){
        if(b->kids[x]&&root->kids[x]){
          transitions.push_back({id[state],id[{root->kids[x],b->kids[x]}]});
        }
      }
    }
    if(b->cnt){
      for(int x=0;x<26;x++){
        if(a->kids[x]&&root->kids[x]){
          transitions.push_back({id[state],id[{a->kids[x],root->kids[x]}]});
        }
      }
    }
    if(a->cnt&&b->cnt){
      for (int x=0;x<26;x++) {
        if(root->kids[x]) {
          transitions.push_back({id[state],id[{root->kids[x],root->kids[x]}]});
        }
      }
    }
  }


  modMatrix mlt;
  mlt.init((int) good_states.size(),(int) good_states.size(),M);


  for (auto &it:transitions){
    it.first--;
    it.second--;
  ///  cout<<" = "<<it.first<<" "<<it.second<<" out of "<<(int)good_states.size()<<"\n";
    assert(0<=it.first&&it.first<(int)good_states.size());
    assert(0<=it.second&&it.second<(int)good_states.size());
  ///  if(it.first==it.second)mlt.a[it.first][it.second]++;
    mlt.a[it.first][it.second]++;
  }

  modMatrix cur;
  cur.init(1,(int)good_states.size(),M);

  assert(0<=id[make_pair(root,root)]-1&&id[make_pair(root,root)]-1<(int)good_states.size());
 /// exit(0);


  cur.a[0][id[make_pair(root,root)]-1]=1;

  mlt=mlt^m;

  cur=cur*mlt;

  int sol=0;

  for (auto &it:good_states){
    if(it.first->cnt&&it.second->cnt){
      addup(sol,cur.a[0][id[it]-1]);
    }
  }

  cout<<sol<<"\n";
  exit(0);
}