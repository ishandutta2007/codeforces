#include <bits/stdc++.h>

using namespace std;

char getinv(char c){
  return 'a'+25-(c-'a');
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

/**
  for (char c='a';c<='z';c++){
    cout<< " : "<<c<<" "<<getinv(c)<<"\n";
  }
  exit(0);**/

  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    if(s[0]>s.back()) {
      for(auto&ch:s) ch=getinv(ch);
    }
    assert(s[0]<=s.back());
    vector<int> inds;
    map<char, vector<int>> w;
    for (int i=1;i<(int)s.size()-1;i++){
      w[s[i]].push_back(i);
    }
    inds.push_back(0);
    for (char c=s[0];c<=s.back();c++) {
      for (auto &i : w[c]) inds.push_back(i);
    }
    inds.push_back((int)s.size()-1);
    cout<<s.back()-s[0]<<" "<<(int)inds.size()<<"\n";
    for (auto &i : inds) cout<<i+1<<" ";
    cout<<"\n";
  }

}