#include <bits/stdc++.h>
using namespace std;

#define int long long

struct T{
  vector<int> f;
  vector<vector<int>> f2;
  int type_first;
  int type_last;
};

T operator + (T a,T b) {
  assert(0<=a.type_first&&a.type_first<=1);
  assert(0<=b.type_first&&b.type_first<=1);
  assert(0<=a.type_last&&a.type_last<=1);
  assert(0<=b.type_last&&b.type_last<=1);
  vector<int> f(2, 0);
  vector<vector<int>> f2(2,vector<int>(2,0));
  int type_first=a.type_first;
  int type_last=b.type_last;
  for(int i=0;i<2;i++){
    f[i]+=a.f[i]+b.f[i];
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      f2[i][j]+=a.f2[i][j]+b.f2[i][j];
    }
  }
  assert(0<=a.type_last&&a.type_last<=1);
  assert(0<=b.type_first&&a.type_first<=1);
  f2[a.type_last][b.type_first]++;
  return {f, f2, type_first, type_last};
}

T get_single(int x) {
  assert(0<=x&&x<=1);

  vector<int> f(2,0);
  vector<vector<int>> f2(2,vector<int>(2,0));
  int type_first=-1;
  int type_last=-1;

  f[x]++;
  type_first=type_last=x;

  return {f, f2, type_first, type_last};
}

bool isok(int dim,int ac,int first,int last){
  assert(0<=ac&&2*ac<=dim);
  assert(0<=first&&first<=2);
  assert(0<=last&&last<=2);
  assert(dim>=1);

  if(dim==1){
    if(first!=last) return 0;
    return 1;
  }

  assert(dim>=2);

  if(ac==0) {
    if(dim==2&&first==0&&last==1) return 0;
    return 1;
  }

  if(ac==1) {
    if (dim==2) {
      return first==0&&last==1;
    }
    if(dim==3){
      return (first==0)||(last==1);
    }
    return 1;
  }

  assert(ac>=2);
  assert(dim>=3);
  assert(1<=ac&&2*ac<=dim);


  assert(ac>=2);
  assert(dim>=3);
  assert(1<=ac&&2*ac<=dim);

  if(first==1){
    dim--;
  }

  if(last==0) {
    dim--;
  }

  return 2*ac<=dim;
}

void p(int x){
  assert(x==0||x==1||x==2);
  if(x==0) cout<<"A";
  if(x==1) cout<<"C";
  if(x==2) cout<<"B";
}

void print(int dim,int ac,int first,int last){
  assert(isok(dim,ac,first,last));
  if(dim==1){
    p(first);
    return;
  }

  assert(dim>=2);

  if(ac==0) {
    p(first);
    for(int i=1;i<=dim-2;i++){
      p(2);
    }
    p(last);
    return;
  }

  if(ac==1) {
    if (dim==2) {
      p(first);
      p(last);
      return;
    }
    if(dim==3){
      p(first);
      if(first==0) p(1); else {

        assert(last==1);
        p(0);
      }
      p(last);
      return;
    }
    p(first);
    if(first==0){
      p(1);
      for(int i=1;i<=dim-3;i++){
        p(2);
      }
    }else{
      p(0);
      p(1);
      for(int i=1;i<=dim-4;i++){
        p(2);
      }
    }
    p(last);
    return;
  }

  assert(ac>=2);
  assert(dim>=3);
  assert(1<=ac&&2*ac<=dim);


  assert(ac>=2);
  assert(dim>=3);
  assert(1<=ac&&2*ac<=dim);

  dim-=(first==1);
  dim-=(last==0);

  if(first==1){
    p(first);
  }


  for (int i=1;i<=ac;i++){
    p(0);
    p(1);
  }
  for(int i=1;i<=dim-2*ac;i++){
    p(2);
  }

  if(last==0) {
    p(last);
  }

  return;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  int k, x, dim0, dim1;
  cin>>k>>x>>dim0>>dim1;

  vector<T> v(k);
  v[0]=get_single(0);
  v[1]=get_single(1);
  for(int i=2;i<k;i++){
    v[i]=v[i-2]+v[i-1];
  }

  for (int ac0=0;2*ac0<=dim0;ac0++) {
    for (int ac1=0;2*ac1<=dim1;ac1++) {
      for (int first0=0;first0<=2;first0++){
        for (int last0=0;last0<=2;last0++) {
          for (int first1=0;first1<=2;first1++){
            for (int last1=0;last1<=2;last1++) {
              bool ok=1;
              ok&=isok(dim0,ac0,first0,last0);
              ok&=isok(dim1,ac1,first1,last1);

              if(!ok)continue;

              int cnt=0;
              cnt+=v.back().f[0]*ac0;
              cnt+=v.back().f[1]*ac1;
              cnt+=v.back().f2[0][0]*(last0==0&&first0==1);
              cnt+=v.back().f2[0][1]*(last0==0&&first1==1);
              cnt+=v.back().f2[1][0]*(last1==0&&first0==1);
              cnt+=v.back().f2[1][1]*(last1==0&&first1==1);
              if(cnt==x){
                print(dim0,ac0,first0,last0);cout<<"\n";
                print(dim1,ac1,first1,last1);
                exit(0);
              }
            }
          }
        }
      }
    }
  }
  cout<<"Happy new year!\n";
  exit(0);
}