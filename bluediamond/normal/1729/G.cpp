#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=(int)1e9+7;
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

const int N=500+7;
const int INF=(int)1e9+7;

int n,m, mn[N][N],ways[N][N];
bool match[N];
string s,t;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  int tt;
  cin>>tt;
  while(tt--){
    cin>>s>>t;
    n=(int)s.size();
    m=(int)t.size();

    for (int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) {
      mn[i][j]=INF;
      ways[i][j]=0;
      match[i]=0;
      if (i>j) {
        mn[i][j]=0;
        ways[i][j]=1;
      }
    }
    for (int i=0;i+m-1<n;i++) {
      match[i+1]=1;
      for (int j=0;j<m;j++) {
        match[i+1]&=(s[i+j]==t[j]);
      }
    }

    for (int l=n;l>=1;l--) {
      for (int r=l;r<=n;r++) {
        int cnt=0;
        for (int j=l;j+m-1<=r;j++) {
          cnt+=match[j];
        }
        if(cnt==0) {
          mn[l][r]=0;
          ways[l][r]=1;
          continue;
        }
        ways[l][r]=0;
        int ff=-1;
        for (int j=l;j+m-1<=r;j++) {
          if (match[j]) {
            mn[l][r]=min(mn[l][r], 1 + mn[l][j-1] + mn[j+m][r]);
          }
        }
        for (int j=l;j+m-1<=r;j++) {
          if (match[j]) {
            /// poate asta sa fie primul din segment?
            if(mn[l][r]!=1 + mn[l][j-1] + mn[j+m][r])continue;
            if(ff==-1 || j<=ff+m-1) { /// da

              addup(ways[l][r], ways[j+m][r]);

            }




            if(ff==-1) ff=j;
          }
        }
      }
    }

    cout<<mn[1][n]<<" "<<ways[1][n]<<"\n";
  }

}