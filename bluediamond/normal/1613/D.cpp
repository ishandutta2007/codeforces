#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

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

void addup(int &a,int b){
  a=add(a,b);
}

void mulup(int &a,int b){
  a=mul(a,b);
}

ostream& operator << (ostream& os, vector<int> v) {
  for (int i=0;i<(int)v.size();i++){
    if(i){
      os<<" ";
    }
    os<<v[i];
  }
  return os;
}

bool isok(vector<int> v){
  set<int>c;
  int mex=0;
  for (auto &x:v){
    c.insert(x);
    while (c.count(mex))mex++;
    if(abs(mex-x)>1)return 0;
  }
  return 1;
}

const int limit=5;
int cnt=0;

void bkt(int need,vector<int>v){
  assert((int)v.size()<=need);
  if(!isok(v))return; /// 445
  if((int)v.size()==need){
    cout<<v<<"\n";
    cnt++;
    return;
  }
  for (int i=0;i<=limit;i++){
    vector<int>v2=v;
    v2.push_back(i);
    bkt(need,v2);
  }
}

void test(int n){
  cnt=0;
  bkt(n,{});
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);


  int t;
  cin>>t;
  for (int tc=1;tc<=t;tc++){
    int n;
    cin>>n;
    map<int,int>dp1,dp2,dp3;
    int cnt1=0,sol=0;
    vector<int>a(n);
    for (auto &x:a){
      cin>>x;
      if(x==1)cnt1++;
      if(x==0){
        addup(dp1[0],dp1[0]);
        addup(dp1[0],1);
      }else{
        addup(dp1[x],dp1[x]);
        addup(dp1[x],dp1[x-1]);


        addup(dp2[x],dp2[x]);
        addup(dp2[x],dp1[x-2]);
        addup(dp2[x],dp3[x-2]);


      }
      addup(dp3[x],dp3[x]);
      addup(dp3[x],dp2[x+2]);
    }

    for (auto &x:dp1)addup(sol,x.second);

    for (auto &x:dp3)addup(sol,x.second);
    for (auto &x:dp2)addup(sol,x.second);



    addup(sol,pw(2,cnt1));
    addup(sol,-1);
    cout<<sol<<"\n";

  }

  return 0;
}