#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

struct T {
  int a;
  int b;
  int i;
  int ret;
};

bool ca(T x, T y) {return x.a<y.a;}
bool ci(T x, T y) {return x.i<y.i;}

void algo(vector<T> &v,vector<T>&v2) {
  int i=-1,n=(int)v2.size(),j=-1;
  for (auto &it : v) {
    while(i+1<n&&v2[i+1].a<it.a){
      i++;
      if (j==-1||v2[i].b<v2[j].b)j=i;
    }
    if (j!=-1&&v2[j].b<it.b) {
      it.ret=v2[j].i;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<T> v(n),v2;
    for (int i=0;i<n;i++) {
      cin>>v[i].a>>v[i].b;
      v[i].i=i+1;
      v[i].ret=-1;
    }
    v2=v;
    for (auto &it : v2) swap(it.a,it.b);
    sort(v.begin(),v.end(),ca);
    sort(v2.begin(),v2.end(),ca);
    algo(v,v);
    algo(v,v2);


    sort(v.begin(),v.end(),ci);
    for (auto &x : v) cout<<x.ret<<  " "; cout<<"\n";
  }

}