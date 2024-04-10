#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int)2e5+7;
int n,m;
int a[N],b[N];
bool ok[N];
bool apare_in_b[26];
bitset<N> f[26];
bitset<N> s[26];
bitset<N> se_mapeaza_la[26][26];

int main() {
#ifndef ONLINE_JUDGE
  freopen ("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

  cin>>n>>m;
  {
    string t;
    cin>>t;
    assert((int)t.size()==n);
    for(int i=0;i<n;i++){
      a[i]=t[i]-'a';
      assert(0<=a[i]&&a[i]<26);
      f[a[i]][i]=1;
    }
  }
  {
    string t;
    cin>>t;
    assert((int)t.size()==m);
    for(int i=0;i<m;i++){
      b[i]=t[i]-'a';
      assert(0<=b[i]&&b[i]<26);
      apare_in_b[b[i]]=1;
      s[b[i]][i]=1;
    }
  }

  for(int i=0;i+m-1<n;i++){
    ok[i]=1;
  }

  for(int x=0;x<26;x++) {
    for(int y=0;y<26;y++) {
      vector<int> A;
      for(int i=0;i<m;i++){
        A.push_back(s[y][i]);
      }
      A.push_back(2);
      for(int i=0;i<n;i++){
        A.push_back(f[x][i]);
      }
      vector<int> ps((int)A.size(),0);
      for(int i=1;i<(int)A.size();i++) {
        ps[i]=ps[i-1];
        while (ps[i]&&A[i]!=A[ps[i]])ps[i]=ps[ps[i]-1];
        if(A[i]==A[ps[i]]) ps[i]++;
        if(ps[i]==m){
          se_mapeaza_la[x][y][i-(2*m)]=1;
        }
      }
    }
  }
  for(int x=0;x<26;x++){
    for(int y=0;y<26;y++){
      se_mapeaza_la[x][y]&=se_mapeaza_la[y][x];
    }
  }

  for(int y=0;y<26;y++) {
    if(apare_in_b[y]==0) continue;
    for(int i=0;i+m-1<n;i++) {
      int cnt=0;
      for(int x=0;x<26;x++){
        if(se_mapeaza_la[x][y][i])cnt++;
      }
      if(cnt==0){
        ok[i]=0;
      }
    }
  }
  vector<int> sol;
  for(int i=0;i+m-1<n;i++){
    if(ok[i]){
      sol.push_back(i);
    }
  }
  cout<<(int)sol.size()<<"\n";
  for(auto &i : sol) {
    cout<<i+1<<" ";
  }
  cout<<"\n";
}