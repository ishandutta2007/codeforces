#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N=(int)5e5+7;
int fact[N],ifact[N];

int comb(int n,int k){
  if(n==-1&&k==-1){
    return 1;
  }
 // assert(0<=k&&k<=n&&n<N);
  return mul(fact[n],mul(ifact[k],ifact[n-k]));
}


int formula(int islands,int cnt){
  assert(islands<=cnt);
  return comb(cnt-1,islands-1);
}

int totalislands(int c00,int cntislands0,int c11,int cntislands1){
  int c0=cntislands0+c00;
  int c1=cntislands1+c11;
  if(c0<cntislands0) return 0;
  if(c1<cntislands1) return 0;
  assert(c0>=cntislands0);
  assert(c1>=cntislands1);
  int sol=1;
  mulup(sol,formula(cntislands0,c0));
  mulup(sol,formula(cntislands1,c1));
  return sol;
}


int total(vector<vector<int>> c, int num){
  for(auto&v:c){
    for(auto&x:v){
      if(x<0){
        return 0;
      }
    }
  }
  int c00=c[0][0];
  int c11=c[1][1];
  int len=1+c[0][0]+c[0][1]+c[1][0]+c[1][1];
  int sol=0;
  if(c[0][1]==c[1][0]){
    /// starts with 0 ends with 0    OR NO!
    /// starts with 1 ends with 1

    if(num&(1<<0)){
      addup(sol,totalislands(c00,c[0][1]+1,c11,c[0][1]));
    }
    if(num&(1<<1)){
      addup(sol,totalislands(c00,c[0][1],c11,c[0][1]+1));
    }
  }
  if(c[0][1]==c[1][0]+1){
    /// starts with 0 ends with 1

    if(num&(1<<0)){
      addup(sol,totalislands(c00,c[0][1],c11,c[0][1]));
    }
  }

  if(c[1][0]==c[0][1]+1){
    /// starts with 1 ends with 0

    if(num&(1<<1)){
      addup(sol,totalislands(c00,c[1][0],c11,c[1][0]));
    }
  }

  return sol;
}

int get(vector<vector<int>> c,string s){
  assert((int)c.size()==2);
  assert((int)c[0].size()==2);
  assert((int)c[1].size()==2);
  int len=1+c[0][0]+c[0][1]+c[1][0]+c[1][1];
  int n=(int)s.size();
  if(n<len){
    return 0;
  }
  if(len<n){
    /// return all possibilities
    return total(c,1<<1);
  }
  /// fix the prefix
  int sol=0;
  for(int pref=1;pref<=n;pref++){
    if(pref>=2){
      int ant=s[pref-2]-'0',now=s[pref-1]-'0';
      c[ant][now]--;
    }
    if(pref==n){
      if(c[0][0]==0&&c[0][1]==0&&c[1][0]==0&&c[1][1]==0){
        addup(sol,1);
      }
    }else{
      if(s[pref]=='1'){
        int ant=s[pref-1]-'0';
        c[ant][0]--;
        addup(sol,total(c,1<<0));
        c[ant][0]++;
      }
    }
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  fact[0]=1;
  for(int i=1;i<N;i++) fact[i]=mul(fact[i-1],i);
  ifact[N-1]=dv(1,fact[N-1]);
  for(int i=N-2;i>=0;i--) ifact[i]=mul(ifact[i+1],i+1);

  if(0){
    for(int i=0;i<=10;i++){
      cout<<i<<" : "<<fact[i]<<" "<<ifact[i]<<" "<<mul(fact[i],ifact[i])<<"\n";
    }
  }

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }





  string s, t;
  cin>>s>>t;
  vector<vector<int>> c(2,vector<int> (2,0));
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      cin>>c[i][j];
    }
  }
  /**
  s = s - 1
  **/
  assert(!s.empty());
  assert(s[0]!='0');
  int cnt1=0;
  for(auto&ch:s){
    cnt1+=(ch=='1');
  }
  if(cnt1==1){
    s.pop_back();
    for(auto&ch:s){
      ch='1';
    }
  }else{
    int pos=(int)s.size()-1;
    while(s[pos]=='0'){
      s[pos]='1';
      pos--;
    }
    s[pos]='0';
  }
  int sol=0;
  addup(sol,get(c,t));
  addup(sol,-get(c,s));

  cout<<sol<<"\n";

  return 0;
}