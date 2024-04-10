#include <bits/stdc++.h>

using namespace std;

const int N=100+7;
int n,mn1,mx2,type[N];
bool good;

void place(int i,int x){
  if (type[i]==0)type[i]=x;
  if (type[i]!=x)good=0;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    cin>>n>>mn1>>mx2;
    good=1;
    for (int i=1;i<=n;i++)type[i]=0;
    place(mn1,1);
    place(mx2,2);


    for (int i=1;i<mn1;i++)place(i,2);
    for (int i=mx2+1;i<=n;i++)place(i,1);

    if (!good){
      cout<<"-1\n";
    }else{
      vector<int> a,b,c;
      for (int i=1;i<=n;i++) {
        if (type[i]==0)c.push_back(i);
        if (type[i]==1)a.push_back(i);
        if (type[i]==2)b.push_back(i);
      }
      if (a.size()>n/2||b.size()>n/2){
        cout<<"-1\n";
      }else{
        while (a.size()<n/2){
          assert(!c.empty());
          a.push_back(c.back());c.pop_back();
        }

        while (b.size()<n/2){
          assert(!c.empty());
          b.push_back(c.back());c.pop_back();
        }
        assert(c.empty());
        assert(a.size()==n/2);
        assert(b.size()==n/2);
        for (auto &x:a)cout<<x<<" ";
        for (auto &x:b)cout<<x<<" ";
        cout<<"\n";
      }
    }
  }

  return 0;
}