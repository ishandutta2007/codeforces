#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int)2e5+7;
int n,q,a[N],when_upd[N];
int upd;
int what;
ll sum=0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n>>q;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    sum+=a[i];
  }
  upd=-1;
  what=0;
  for (int iq=1;iq<=q;iq++) {
    int type;
    cin>>type;
    if (type==1) {
      int i,x;
      cin>>i>>x;
      if (when_upd[i]<upd) {
        sum-=what;
      }else{
        sum-=a[i];
      }
      a[i]=x;
      when_upd[i]=iq;
      sum+=x;
    }else{
      assert(type==2);
      int x;
      cin>>x;
      upd=iq;
      what=x;
      sum=(ll)n*what;
    }
    cout<<sum<<"\n";
  }

  return 0;
}