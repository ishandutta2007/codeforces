#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;


class SuffixArray {
private:
  bool stringSet;
  string s;
public:
  explicit SuffixArray(string s) : s(s), stringSet(1) {
  }

  SuffixArray() : stringSet(0) {
  }

  SuffixArray(SuffixArray& other) = default;
  SuffixArray(SuffixArray&& other) = default;
  ~SuffixArray() = default;

  SuffixArray operator = (SuffixArray& other) {}
  SuffixArray operator = (SuffixArray&& other) noexcept {}


  bool isStringSet() {
    return stringSet;
  }

  void setString(string newString) {
    stringSet = 1;
    s = newString;
  }

  void unsetString() {
    stringSet = 0;
  }

  vector<int> computeSuffixOrder() {
    assert(stringSet);

    map<char, int> stringChars;
    for (auto &ch : s) {
      stringChars[ch] = 0;
    }

    int maxValue = 0;

    for (auto &it : stringChars) {
      it.second = maxValue++;
    }

    int n = (int) s.size();

    vector<int> v(n);
    vector<int> cnt(n, 0);
    vector<int> order(n, -1);
    vector<int> equivalenceClass(n);
    vector<int> equivalenceClassCopy(n);
    vector<int> newOrder(n);

    for (int i = 0; i < n; i++) {
      v[i] = stringChars[s[i]];
      cnt[v[i]]++;
      equivalenceClass[i] = v[i];
    }
    for (int i = 1; i < maxValue; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      order[--cnt[v[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      cnt[i] = 0;
    }

    int currentLength = 1;
    while (currentLength < n) {
      for (auto &i : order) {
        cnt[equivalenceClass[i]]++;
        equivalenceClassCopy[i] = equivalenceClass[i];
      }
      for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
      }
      for (int it = n - 1; it >= 0; it--) {
        int j = (order[it] - currentLength + n) % n;
        newOrder[--cnt[equivalenceClass[j]]] = j;
      }
      order = newOrder;
      int currentClass = 0;
      for (int j = 0; j < n; j++) {
        currentClass += (j == 0 || make_pair(equivalenceClassCopy[order[j]], equivalenceClassCopy[(order[j] + currentLength) % n]) != make_pair(equivalenceClassCopy[order[j - 1]], equivalenceClassCopy[(order[j - 1] + currentLength) % n]));
        equivalenceClass[order[j]] = currentClass - 1;
        cnt[j] = 0;
      }
      currentLength *= 2;
    }

    return order;
  }

  pair<vector<int>, vector<int>> computeSuffixOrderAndLcp() {
    assert(stringSet);

    map<char, int> stringChars;
    for (auto &ch : s) {
      stringChars[ch] = 0;
    }

    int maxValue = 0;

    for (auto &it : stringChars) {
      it.second = maxValue++;
    }

    int n = (int) s.size();

    vector<int> v(n);
    vector<int> cnt(n, 0);
    vector<int> order(n, -1);
    vector<int> equivalenceClass(n);
    vector<int> equivalenceClassCopy(n);
    vector<int> newOrder(n);

    for (int i = 0; i < n; i++) {
      v[i] = stringChars[s[i]];
      cnt[v[i]]++;
      equivalenceClass[i] = v[i];
    }
    for (int i = 1; i < maxValue; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      order[--cnt[v[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      cnt[i] = 0;
    }

    int currentLength = 1;
    while (currentLength < n) {
      for (auto &i : order) {
        cnt[equivalenceClass[i]]++;
        equivalenceClassCopy[i] = equivalenceClass[i];
      }
      for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
      }
      for (int it = n - 1; it >= 0; it--) {
        int j = (order[it] - currentLength + n) % n;
        newOrder[--cnt[equivalenceClass[j]]] = j;
      }
      order = newOrder;
      int currentClass = 0;
      for (int j = 0; j < n; j++) {
        currentClass += (j == 0 || make_pair(equivalenceClassCopy[order[j]], equivalenceClassCopy[(order[j] + currentLength) % n]) != make_pair(equivalenceClassCopy[order[j - 1]], equivalenceClassCopy[(order[j - 1] + currentLength) % n]));
        equivalenceClass[order[j]] = currentClass - 1;
        cnt[j] = 0;
      }
      currentLength *= 2;
    }

    vector<int> lcp(n, 0);
    int k = 0;

    for (auto &i : equivalenceClass) {
      k = max(0, k - 1);
      if (i) {
        int a = order[i - 1], b = order[i];
        while (max(a, b) + k < n && v[a + k] == v[b + k]) {
          k++;
        }
        lcp[i] = k;
      }
    }

    vector<int> newLcp(n - 1);
    for (int i = 0; i < n - 1; i++) {
      newLcp[i] = lcp[i + 1];
    }

    return {order, newLcp};
  }
};

const int N=(int)2e5+7;
int n;
string s;
string t;
bool ok[N];
int gol[N];

int tt[N],sz[N];

int root(int x){
  if(tt[x]==x)return x;
  return tt[x]=root(tt[x]);
}

int big;

void unite(int x,int y){
  x=root(x);
  y=root(y);

  if(x==y)return;
  tt[x]=y;
  sz[y]+=sz[x];
  big=max(big,sz[y]);
}

vector<int> who[N];

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

  for (int i=0;i<N;i++)tt[i]=i;

  cin>>n>>s>>t;
  reverse(s.begin(),s.end());
  reverse(t.begin(),t.end());

  for (int i=0;i<n;i++)ok[i]=!(t[i]-'0');

  SuffixArray suf(s+"$");
  auto g=suf.computeSuffixOrderAndLcp();

  for (int i=0;i<g.first.size();i++)gol[g.first[i]]=i;


  if(home){
  cout<<" = "<<s<<"\n";
  cout<<" = "<<t<<"\n";

  for (auto &it:g.first)cout<<it<<" "; cout<<"\n";
  for (auto &it:g.second)cout<<it<<" "; cout<<"\n";
  }
  ll sol=0;
  for (int i=0;i<n;i++){
    if(ok[i]){
      sol=n-i;
      break;
    }
  }

  function<int(int,int)>getlcp=[&](int l,int r){
    assert(l!=r);
    l=gol[l];
    r=gol[r];

    if(l>r)swap(l,r);
    r--;
    int sol=(int)1e9;
    for (int i=l;i<=r;i++)sol=min(sol,g.second[i]);
    return sol;
  };

  big=0;

  for (int i=0;i<g.first.size();i++){
    sz[i]=ok[g.first[i]];
    big=max(big,sz[i]);
  }



  for (int i=0;i<g.second.size();i++){
    who[g.second[i]].push_back(i);
  }

  for (int c=N-1;c>=0;c--){
    for (auto &i:who[c]){
      unite(i+1,i);
     /// cout<<"\t\tunesc "<<i<<" cu "<<i+1<<"\n";
    }
    if(big>1){
      if(home)cout<<c<<" : "<<big<<"\n";
      sol=max(sol,(ll)c*big);
    }
    if(home&&big>1){
      cout<<"\t\t";
      for (int i=0;i<g.first.size();i++){
        cout<<root(i)<<" ";
      }
      cout<<"\n";
    }
  }


  /**
  for (int low=0;low<n;low++){
    int cur=(int)1e9,cnt=ok[g.first[low]];
    for (int high=low+1;high<n;high++){
      cur=min(cur,g.second[high-1]);
      cnt+=ok[g.first[high]];
      sol=max(sol,(ll)cur*cnt);
    }
  }**/
  cout<<sol<<"\n";

  return 0;
}