#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
const int FACTN=300000+7;
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
int fact[FACTN],ifact[FACTN];
void computeFACT(){
  fact[0]=1;
  for(int i=1;i<FACTN;i++)fact[i]=mul(fact[i-1],i);
  ifact[FACTN-1]=dv(1,fact[FACTN-1]);
  for(int i=FACTN-2;i>=0;i--)ifact[i]=mul(ifact[i+1],i+1);
}
int getCOMB(int n,int k){
  return mul(fact[n],mul(ifact[k],ifact[n-k]));
}

const int N=500+7;
int n;
int a[2*N][N];
int f[N][N]; /// f[col][val]
bool act[2*N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE
  int t;
  cin>>t;
  for (int tc=1;tc<=t;tc++){
    cin>>n;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=n;j++) {
        f[i][j]=0;
      }
    }
    for (int i=1;i<=2*n;i++) {
      act[i]=1;
    }
    for (int i=1;i<=2*n;i++) {
      for (int j=1;j<=n;j++) {
        cin>>a[i][j];
        f[j][a[i][j]]++;
      }
    }
    queue<int> q;
    for (int i=1;i<=2*n;i++) {
      if (!act[i]) continue;
      for (int j=1;j<=n;j++){
        if(f[j][a[i][j]]==1){
          q.push(i);
          break;
        }
      }
    }
    vector<int> sol;
    int ways=1;
    for (int steps=1;steps<=n;steps++) {
      while(!q.empty()&&act[q.front()]==0){
        q.pop();
      }
      int guy;
      if (!q.empty()) {
        guy=q.front();
        bool fo=0;
        for (int j=1;j<=n;j++) {
          fo|=(f[j][a[guy][j]]==1);
        }
        assert(fo);
      }else{
        guy=1;
        while(act[guy]==0) guy++;
        mulup(ways, 2);
      }
      sol.push_back(guy);
      act[guy]=0;
      for (int j=1;j<=n;j++) f[j][a[guy][j]]--;
      for (int i=1;i<=2*n;i++) {
        if(!act[i]) continue;
        for (int j=1;j<=n;j++) {
          if (a[i][j]==a[guy][j]){
            act[i]=0;
            for (int j=1;j<=n;j++) f[j][a[i][j]]--;
            break;
          }
        }
      }
      for (int i=1;i<=2*n;i++) {
        if (!act[i]) continue;
        for (int j=1;j<=n;j++) {
          if(f[j][a[i][j]]==1){
            q.push(i);
            break;
          }
        }
      }
    }
    cout<<ways<<"\n";
    for (auto &i : sol) {
      cout<<i<<" ";
    }
    cout<<"\n";
  }
  exit(0);
}