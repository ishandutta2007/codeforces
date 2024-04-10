#include <bits/stdc++.h>

using namespace std;

bool home = 1;

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
       /// cout << i << " and " << b << "\n";
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

const int N=(int)5e5+7;
int n,q;
string s[N],total;

void print(vector<int>v){
  cout<<"---->";
  for (auto &i:v){
    cout<<i<<" ";
  }
  cout<<"\n";
}

int og[N],la[N],so[N],memo[N];
int aib[2*N];

void add(int i,int x){
  i+=2;
  while(i<2*N)aib[i]+=x,i+=i&(-i);
}

int pref(int i){
  i+=2;
  int sol=0;
  while(i)sol+=aib[i],i-=i&(-i);
  return sol;
}

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


  cin>>n>>q;
  for (int i=1;i<=n;i++){
    cin>>s[i];
    og[i]=(int)total.size();
    total+=s[i]+"$";
    la[i]=(int)total.size()-1;
  }
  total+=(char)('$'-1);
  SuffixArray kek(total);
  auto lol=kek.computeSuffixOrderAndLcp();
  vector<int>kol((int)lol.first.size());
  for (int i=0;i<(int)lol.first.size();i++){
    kol[lol.first[i]]=i;
  }
  vector<int>lg((int)lol.first.size());

  for (int i=2;i<(int)lol.first.size();i++)lg[i]=1+lg[i/2];

  vector<vector<int>>tab(lg.back()+2,vector<int>(lol.first.size(),0));
  for (int i=0;i<(int)lol.first.size()-1;i++)tab[0][i]=lol.second[i];

  for(int k=1;(1<<k)<lol.first.size()-1;k++){
    for (int i=0;i+(1<<k)-1<(int)lol.first.size()-1;i++){
      tab[k][i]=min(tab[k-1][i],tab[k-1][i+(1<<(k-1))]);
    }
  }

  function<int(int,int)>getmn=[&](int l,int r){
    if(l>r)return (int)1e9;
    int k=lg[r-l+1];
    return min(tab[k][l],tab[k][r-(1<<k)+1]);
  };

  function<int(int,int)>lcp=[&](int i,int j){
    i=kol[i];
    j=kol[j];
    if(i>j)swap(i,j);
    return getmn(i,j-1);
  };

  vector<vector<int>>rq;
//  exit(0);
  for (int iq=1;iq<=q;iq++){
    int l,r,k;
    cin>>l>>r>>k;
    int sol=0;
    int wn=(int)s[k].size();
    int lft=kol[og[k]],rgh=kol[og[k]];
    int lo=0,hi=lft-1;
    while(lo<=hi){
      int mid=(lo+hi)/2;
      if(lcp(lol.first[mid],og[k])>=(int)s[k].size()){
        lft=mid;hi=mid-1;
      }else lo=mid+1;
    }
    lo=rgh+1;
    hi=(int)lol.first.size()-1;
    while(lo<=hi){
      int mid=(lo+hi)/2;
      if(lcp(og[k],lol.first[mid])>=(int)s[k].size()){
        rgh=mid;lo=mid+1;
      }else hi=mid-1;
    }
   /// cout<<iq<<" : "<<lft<<" vs "<<rgh<<"\n";
    rq.push_back({la[r],iq,+1,lft,rgh});
    rq.push_back({og[l]-1,iq,-1,lft,rgh});
    for (int kl=lft;kl<=rgh;kl++){
      int pz=lol.first[kl];
      if(og[l]<=pz&&pz<=la[r]){
        sol++;
      }
    }
   // cout<<sol<<"\n";
  }
  vector<pair<int,int>>z;
  for (int i=0;i<(int)lol.first.size();i++)z.push_back({lol.first[i],i});
sort(z.begin(),z.end());
int pz=0;
  sort(rq.begin(),rq.end());
  for (auto &it:rq){
    int limit=it[0];
    int i=it[1];
    int sgn=it[2];
    int lft=it[3];
    int rgh=it[4];
    int cur=0;
    while(pz<(int)z.size()&&z[pz].first<=limit){
      add(z[pz].second,1);
      pz++;
    }
    cur=pref(rgh)-pref(lft-1);
    memo[i]+=sgn*cur;
  }
  for (int i=1;i<=q;i++){
    cout<<memo[i]<<"\n";
  }
  return 0;
}