#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

#define int long long
const int N=(int)5e5+7;
int n;
int init[N],d[N],pref[N];

int gallai(int add){
  for(int i=1;i<n;i++){
    d[i]=init[i];
  }

  d[n]=add;

  int pos=n;
  while(pos-1>=1&&d[pos-1]<d[pos]){
    swap(d[pos],d[pos-1]);
    pos--;
  }

  for(int i=1;i<n;i++){
    assert(d[i]>=d[i+1]);
  }

  for(int i=1;i<=n;i++){
    pref[i]=pref[i-1]+d[i];
  }

  int suffix=n+1;

  for(int i=1;i<=n;i++){
    int a=pref[i];
    int b=0;
    while(suffix-1>=1&&d[suffix-1]<=i) suffix--;
    b+=max(0LL,suffix-i-1)*i;
    b+=pref[n]-pref[max(i+1,suffix)-1];
    if(a>i*(i-1)+b){
      if(i<pos){
        return -1;
      }else{
        return +1;
      }
    }
  }
  return 0;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin>>n;

  n++;
  int z=0;


  for(int i=1;i<n;i++){
    cin>>init[i];
    z+=init[i];
  }



  sort(init+1,init+n+1);
  reverse(init+1,init+n+1);

  vector<int> inc;
  for(int i=0;i<=n;i++){
    if((z+i)%2==0){
      inc.push_back(i);
    }
  }

  vector<int> sol;

  int low=0,high=(int)inc.size()-1,first=(int)inc.size(),last=-1;

  while(low<=high){
    int mid=(low+high)/2;
    if(gallai(inc[mid])==-1){
      low=mid+1;
    }else{
      high=mid-1;
      first=mid;
    }
  }

  low=0,high=(int)inc.size()-1;


  while(low<=high){
    int mid=(low+high)/2;
    if(gallai(inc[mid])==+1){
      high=mid-1;
    }else{
      last=mid;
      low=mid+1;
    }
  }

  for(int i=first;i<=last;i++){
    int x=inc[i];
    sol.push_back(x);
  }


  if(sol.empty()){
    cout<<"-1\n";
  }else{
    for(auto&x:sol){
      cout<<x<<" ";
    }
    cout<<"\n";
  }

  return 0;
}