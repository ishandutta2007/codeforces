#include <bits/stdc++.h>

bool home = 1;

using namespace std;

///#define int long long

string del(string input){
  string s;
  for(auto&ch:input){
    if (ch == 'B') continue;
    s+=ch;
    if((int)s.size()>=2&&s[(int)s.size()-1]==s[(int)s.size()-2]) s.pop_back(), s.pop_back();
  //  if((int)s.size()>=4&&s[(int)s.size()-1]=='B'&&s[(int)s.size()-2]=='A'&&s[(int)s.size()-3]=='B'&&s[(int)s.size()-4]=='A') s.pop_back(), s.pop_back(), s.pop_back(), s.pop_back();
  //  if((int)s.size()>=4&&s[(int)s.size()-1]=='C'&&s[(int)s.size()-2]=='B'&&s[(int)s.size()-3]=='C'&&s[(int)s.size()-4]=='B') s.pop_back(), s.pop_back(), s.pop_back(), s.pop_back();
  }
  return s;
}

vector<string> MOVES;

vector<string> gen_all(string s){
  vector<string> all;
  int n=(int)s.size();
  for(int plen=0;plen<=n;plen++){
    string pre,suf;
    for(int i=0;i<plen;i++) pre+=s[i];
    for(int i=plen;i<n;i++) suf+=s[i];
    for (auto &mv:MOVES) {
      all.push_back(pre + mv + suf);
    }
  }

  for (int i = 0; i < n; i++) {
    string current;
    for (int len = 1; i + len - 1 < n && len <= 4; len++) {
      current += s[i + len - 1];
      bool is_move = 0;
      for (auto &mv : MOVES) {
        is_move |= (current == mv);
      }
      if(is_move) {
        string add;
        for (int k = 0; k < i; k++) add += s[k];
        for (int k = i + len; k < n; k++) add += s[k];
        all.push_back(add);
      }
    }
  }
  return all;
}

set<string> seen;

void dfs(string s) {
  if (seen.count(s) || (int) s.size() >= 10) return;
  seen.insert(s);
  auto V = gen_all(s);
  for (auto &t : V) {
    dfs(t);
  }
}

void explore(string s) {
  seen.clear();
  dfs(s);
  int cnt = 0;
  for (auto &it : seen) {
    cout << ++cnt << " : " << it << "\n";
  }
  cout << "read\n";
  while (1) {
    string query;
    cin >> query;
    cout << (seen.count(query) ? "YES" : "NO") << "\n";
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  MOVES.push_back("AA");
  MOVES.push_back("BB");
 // MOVES.push_back("CC");
 // MOVES.push_back("ABAB");
 // MOVES.push_back("BCBC");

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  /*
  explore("CA");
  exit(0);*/


  int t;
  cin>>t;
  while(t--){
    string a,b;
    cin>>a>>b;

    bool ok=1;
    for(char want='A';want<='C';want++){
      int F=0;
      for (auto &ch : a) F ^= (ch == want);
      for (auto &ch : b) F ^= (ch == want);
      ok &= (F == 0);
    }
    a=del(a);
    b=del(b);
    string AC1, AC2;
    for (auto &ch : a) if (ch == 'A' || ch == 'C') AC1 += ch;
    for (auto &ch : b) if (ch == 'A' || ch == 'C') AC2 += ch;
    ok &= (AC1 == AC2);
    cout << (ok ? "YES" : "NO") << "\n";
  //  cout<<((del(a)==del(b))?"YES":"NO")<<"\n";
  }


}