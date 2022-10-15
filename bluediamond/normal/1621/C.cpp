#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int ask(int p) {
  cout<<"? "<<p<<endl;
  int r;
  cin>>r;
  return r;
}

const int N=(int)1e4+7;
int n;
int a[N];

signed main() {
  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++){
      a[i]=0;
    }
    for (int i=1;i<=n;i++){
      if(a[i]==0){
        set<int>seen;
        vector<int>cur;
        while (1){
          int x=ask(i);
          if(seen.count(x)){
            break;
          }
          seen.insert(x);
          cur.push_back(x);
        }
        for (int i=0;i<(int)cur.size();i++){
          a[cur[i]]=cur[(i+1)%(int)cur.size()];
        }
      }
    }
    cout<<"! ";
    for (int i=1;i<=n;i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}