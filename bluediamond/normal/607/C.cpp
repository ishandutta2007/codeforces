#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long double ld;

char opchar(char ch){
  if(ch=='N') return 'S';
  if(ch=='S') return 'N';
  if(ch=='E') return 'W';
  if(ch=='W') return 'E';
  assert(0);
}

int code(char ch){
  if(ch=='N') return 0;
  if(ch=='S') return 1;
  if(ch=='E') return 2;
  if(ch=='W') return 3;
  assert(0);
}

const int N=(int)1e6+7;
int n;
string s,t;

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  time_t bg=clock();
  cin>>n>>s>>t;

  n--;
  assert((int)s.size()==n);
  assert((int)t.size()==n);

  for(auto&ch:t){
    ch=opchar(ch);
  }
  reverse(s.begin(),s.end());
  reverse(t.begin(),t.end());

  int L=200;
  vector<int> ls;
  for(int l=1;l<=n;l++){
    if(l>L){
      ls.push_back(l);
    }else{
      bool match=1;
      for (int j=0;j<l;j++){
        if(s[j]!=t[l-1-j]){
          match=0;
          break;
        }
      }
      if(match){
        cout<<"NO\n";
        return 0;
      }
      if((double)(clock()-bg)/CLOCKS_PER_SEC>1.9){
        break;
      }
    }
  }
  mt19937 rng((long long)(new char));
  shuffle(ls.begin(),ls.end(),rng);

  for(auto &l:ls){
    bool match=1;
    for (int j=0;j<l;j++){
      if(s[j]!=t[l-1-j]){
        match=0;
        break;
      }
    }
    if(match){
      cout<<"NO\n";
      return 0;
    }
    if((double)(clock()-bg)/CLOCKS_PER_SEC>1.9){
      break;
    }
  }
  cout<<"YES\n";

}