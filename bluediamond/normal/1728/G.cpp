#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
}
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
}
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return mul(a,pw(b,M-2));
}
void addup(int &a,int b){
  a=add(a,b);
}
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}
int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int d,n,m;
  cin>>d>>n>>m;
  vector<int> lens(n);
  for (auto &x:lens){
    cin>>x;
  }
  sort(lens.begin(),lens.end());
  vector<int> p(m);
  for (auto &x:p){
    cin>>x;
  }
  sort(p.begin(),p.end());
  int q;
  cin>>q;
  vector<int> qs(q);
  for (auto &x:qs){
    cin>>x;
  }
  const int INF=(int)1e9+7;

  function<int(int)>get = [&](int i){
    if(0<=i&&i<m){
      return p[i];
    }
    if(i<0){
      return -INF;
    }
    assert(i>=m);
    return +INF;
  };

  vector<vector<int>> ways_pref(n+1,vector<int>(m+1,0));
  vector<vector<int>> ways_suf(n+1,vector<int>(m+1,0));
  ways_pref[0][0]=1;
  for (int it=0;it<n;it++) {
    int l=lens[it];
    for (int i=0;i<m;i++) {
      int stop=min(d,l-1-p[i]);
      if(0<=stop){
        addup(ways_pref[it+1][i],mul(ways_pref[it][i],stop+1));
      }
      int start=max(0,stop+1);
      for (int j=i;j<=m;j++){
        int stop=min(get(j)-l-1,d);
        int st=start;
        if(j!=i){
          st=max(start,get(j-1)-l);
        }
        if(st<=stop){
          addup(ways_pref[it+1][j],mul(stop-st+1,ways_pref[it][i]));
        }
      }
    }
    addup(ways_pref[it+1][m],mul(d+1,ways_pref[it][m]));
  }
  ways_suf[n][m]=1;
  for (int it=n-1;it>=0;it--) {
    int l=lens[it];
    for (int i=1;i<=m;i++) {
      int stop=min(d,p[i-1]-1-l);
      if(0<=stop){
        addup(ways_suf[it][i],mul(ways_suf[it+1][i],stop+1));
      }
      int start=max(0,stop+1);
      for (int j=0;j<=i;j++){
        int stop=min(d,l-1-get(j-1));
        int st=start;
        if(j!=i){
          st=max(start,l-get(j));
        }
        if(st<=stop){
          addup(ways_suf[it][j],mul(stop-st+1,ways_suf[it+1][i]));
        }
      }
    }
    addup(ways_suf[it][0],mul(d+1,ways_suf[it+1][0]));
  }

  ll hs=0;

  for (auto &x:qs){

    {
      int cnt_smaller=0;
      int low=0,high=n-1;
      while(low<=high){
        int mid=(low+high)/2;
        if(lens[mid]<=x){
          low=mid+1;
          cnt_smaller=mid+1;
        }else{
          high=mid-1;
        }
      }
      assert(0<=cnt_smaller&&cnt_smaller<=n);
      assert(0<=cnt_smaller&&cnt_smaller<=n);
      int sol=0;
      for (int i=0;i<=m;i++){
        for (int j=0;j<=i;j++){
          addup(sol,mul(d+1,ways_pref[cnt_smaller][i],ways_suf[cnt_smaller][j]));

        }
      }
      for (int i=0;i<=m;i++) {
        for (int j=i+1;j<=m;j++) {
          int st=max(0,max(p[j-1]-x,x-p[i]));
          if(st<=d){
            addup(sol,mul(d-st+1,ways_pref[cnt_smaller][i],ways_suf[cnt_smaller][j]));
          }
        }
      }
      hs=hs*777777777777LL+sol;
      cout<<sol<<"\n";
    }
  }

  //cout<<hs<<"\n";
  //assert(hs==-2249136134542044482);


  return 0;
}
/**

**/