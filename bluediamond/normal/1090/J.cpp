#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

const int N=(int) 2e5+7;
int n,m,v1[N],v2[N],v[2*N],z[2*N],sz,g1[N],g2[N],go[N],cnt[N];

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

  {
    string str;
    cin>>str;
    n=(int)str.size();
    for(int i=1;i<=n;i++){
      v1[i]=str[i-1]-'a';
    }
  }

  {
    string str;
    cin>>str;
    m=(int)str.size();
    for(int i=1;i<=m;i++){
      v2[i]=str[i-1]-'a';
    }
  }

  {
    sz=0;
    for(int i=1;i<=m;i++){
      v[sz++]=v2[i];
    }
    for(int i=1;i<=n;i++){
      v[sz++]=v1[i];
    }
    for(int i=1;i<=n+m;i++){
      v[sz++]=-1;
    }
    z[0]=sz;
    int l=0,r=0;
    for(int i=1;i<sz;i++){
      if(i<=r){
        z[i]=min(r-i+1,z[i-l]);
      }
      while(i+z[i]<sz&&v[i+z[i]]==v[z[i]]){
        z[i]++;
      }
      if(i+z[i]-1>r){
        l=i;
        r=i+z[i]-1;
      }
    }
    for(int i=1;i<=n;i++){
      g1[i]=z[m+i];
      go[i]=min(n-i,g1[i]);
    }
    for(int i=1;i<=m;i++){
      g2[i]=max(g2[i-1],z[i]+i);
      cnt[i]=cnt[i-1]+(g2[i-1]>=i);
    }
  }
  ll sol=0;
  for(int a=1;a<=n;a++){
    sol+=cnt[min(m,go[a]+1)];
    sol+=max(0,min(g2[go[a]],m)-go[a]-1);
  }
  cout<<n*(ll)m-sol<<"\n";


  return 0;
}