#include <bits/stdc++.h>

using namespace std;

const int B=20;
const int N=(int)1e5+7;
const int INF=(int)1e9+7;
int dim,num_bits,a[N],pop[1<<B],f[1<<B];
int cnt[B+1][1<<B],s[2][1<<B];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input.txt", "r", stdin);


  cin>>num_bits>>dim;

  for(int i=1;i<(1<<num_bits);i++){
    int j=i&(-i);
    pop[i]=pop[i-j]+1;
  }
  for(int bit=0;bit<num_bits;bit++){
    string s;
    cin>>s;
    assert((int)s.size()==dim);
    for(int i=0;i<dim;i++){
      if(s[i]=='1'){
        a[i]+=(1<<bit);
      }
    }
  }
  for(int i=0;i<dim;i++){
    f[a[i]]++;
  }


  int sol=INF;

  for(int mask=0;mask<(1<<num_bits);mask++){
    cnt[0][mask]+=f[mask];
    s[0][mask]+=f[mask];
  }
  for(int c=1;c<=num_bits;c++){
    int p=c%2,p0=(c-1)%2;
    for(int i=0;i<(1<<num_bits);i++){
      for(int d=0;d<num_bits;d++){
        cnt[c][i]+=s[p0][i^(1<<d)]-s[p][i];
      }
      cnt[c][i]/=c;
    }
    for(int i=0;i<(1<<num_bits);i++){
      s[p][i]+=cnt[c][i];
    }
  }
  for(int mask=0;mask<(1<<num_bits);mask++){
    int cur=0;
    for(int z=0;z<=num_bits;z++){
      cur+=min(z,num_bits-z)*cnt[z][mask];
    }
    sol=min(sol,cur);
  }
  cout<<sol<<"\n";

  return 0;
}