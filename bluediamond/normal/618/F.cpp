#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;
const int N = (int) 1e6 + 7;
int n,lrg[N];

pair<int,int>a[N];
pair<int,int>b[N];

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


  cin>>n;
  for (int i=1;i<=n;i++){cin>>a[i].first;a[i].second=i;}
  for (int i=1;i<=n;i++){cin>>b[i].first;b[i].second=i;}

  sort(a+1,a+n+1);
  sort(b+1,b+n+1);

  for (int i=1;i<=n;i++)a[i].first+=a[i-1].first;
  for (int i=1;i<=n;i++)b[i].first+=b[i-1].first;

  bool inv=0;
  if(a[n]>b[n]){
    inv=1;
    for (int i=1;i<=n;i++)swap(a[i],b[i]);
  }

  int j=0;
  for (int i=0;i<=n;i++){
    while(j+1<=n&&b[j+1]<=a[i]){
      j++;
    }
    lrg[i]=j;
  }

  /// for i = 0...n : a[i]-b[lrg[i]]<=n-1 => at least two equal

  /// a[i1]-b[j1]=a[i2]-b[j2]
  /// a[i1]-a[i2]=b[j1]-b[j2]

  set<int>deja;
  for (int i=0;i<=n;i++){
    int current=a[i].first-b[lrg[i]].first;
    if(deja.count(current)){
      for (int i2=0;i2<i;i2++){
        if(a[i2].first-b[lrg[i2]].first==current){

        ///  cout<<lrg[i]<< " and "<<lrg[i2]<<"\n";
        if(!inv){
        cout<<i-i2<<"\n";for (int itr=i2+1;itr<=i;itr++)cout<<a[itr].second<<" "; cout<<"\n";
        cout<<lrg[i]-lrg[i2]<<"\n";for (int itr=lrg[i2]+1;itr<=lrg[i];itr++)cout<<b[itr].second<<" "; cout<<"\n";}else{
        cout<<lrg[i]-lrg[i2]<<"\n";for (int itr=lrg[i2]+1;itr<=lrg[i];itr++)cout<<b[itr].second<<" "; cout<<"\n";
        cout<<i-i2<<"\n";for (int itr=i2+1;itr<=i;itr++)cout<<a[itr].second<<" "; cout<<"\n";
        }exit(0);
        }
      }
      assert(0);
    }else deja.insert(current);
  }assert(0);

  return 0;
}