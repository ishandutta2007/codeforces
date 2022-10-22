#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int prova(int k,vector<string>v,int stampa){
  vector<string> p=v;
  int N=v.size();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='O')v[i][j]='X';
      if(v[i][j]=='X' && (i+j)%3==k)v[i][j]='O';
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X' && v[i][j]!=p[i][j]){
        v[i][j]='O';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='O' && v[a+1][j]=='O' && v[a+2][j]=='O')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='O' && v[i][a+1]=='O' && v[i][a+2]=='O')ok=0;
        }
        if(ok==0)v[i][j]='X';
      }
    if(v[i][j]=='O' && v[i][j]!=p[i][j]){
        v[i][j]='X';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='X' && v[a+1][j]=='X' && v[a+2][j]=='X')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='X' && v[i][a+1]=='X' && v[i][a+2]=='X')ok=0;
        }
        if(ok==0)v[i][j]='O';
      }
    }
  }
  if(stampa)for(auto i:v)cout<<i<<'\n';
  int t=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]!=p[i][j])t++;
    }
  }
  return t;
}
int prova1(int k,vector<string>v,int stampa){
  vector<string> p=v;
  int N=v.size();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X')v[i][j]='O';
      if(v[i][j]=='O' && (i+j)%3==k)v[i][j]='X';
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X' && v[i][j]!=p[i][j]){
        v[i][j]='O';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='O' && v[a+1][j]=='O' && v[a+2][j]=='O')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='O' && v[i][a+1]=='O' && v[i][a+2]=='O')ok=0;
        }
        if(ok==0)v[i][j]='X';
      }
    if(v[i][j]=='O' && v[i][j]!=p[i][j]){
        v[i][j]='X';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='X' && v[a+1][j]=='X' && v[a+2][j]=='X')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='X' && v[i][a+1]=='X' && v[i][a+2]=='X')ok=0;
        }
        if(ok==0)v[i][j]='O';
      }
    }

  }
  if(stampa)for(auto i:v)cout<<i<<'\n';
  int t=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]!=p[i][j])t++;
    }
  }
  return t;
}

int prova2(int k,vector<string>v,int stampa){
  vector<string> p=v;
  int N=v.size();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='O')v[i][j]='X';
      if(v[i][j]=='X' && (i-j+30000)%3==k)v[i][j]='O';
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X' && v[i][j]!=p[i][j]){
        v[i][j]='O';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='O' && v[a+1][j]=='O' && v[a+2][j]=='O')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='O' && v[i][a+1]=='O' && v[i][a+2]=='O')ok=0;
        }
        if(ok==0)v[i][j]='X';
      }
    if(v[i][j]=='O' && v[i][j]!=p[i][j]){
        v[i][j]='X';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='X' && v[a+1][j]=='X' && v[a+2][j]=='X')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='X' && v[i][a+1]=='X' && v[i][a+2]=='X')ok=0;
        }
        if(ok==0)v[i][j]='O';
      }
    }
  }
  if(stampa)for(auto i:v)cout<<i<<'\n';
  int t=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]!=p[i][j])t++;
    }
  }
  return t;
}
int prova3(int k,vector<string>v,int stampa){
  vector<string> p=v;
  int N=v.size();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X')v[i][j]='O';
      if(v[i][j]=='O' && (i-j+30000)%3==k)v[i][j]='X';
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X' && v[i][j]!=p[i][j]){
        v[i][j]='O';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='O' && v[a+1][j]=='O' && v[a+2][j]=='O')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='O' && v[i][a+1]=='O' && v[i][a+2]=='O')ok=0;
        }
        if(ok==0)v[i][j]='X';
      }
    if(v[i][j]=='O' && v[i][j]!=p[i][j]){
        v[i][j]='X';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='X' && v[a+1][j]=='X' && v[a+2][j]=='X')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='X' && v[i][a+1]=='X' && v[i][a+2]=='X')ok=0;
        }
        if(ok==0)v[i][j]='O';
      }
    }
  }
  if(stampa)for(auto i:v)cout<<i<<'\n';
  int t=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]!=p[i][j])t++;
    }
  }
  return t;
}
void solve(){
  int N;
  cin>>N;
  vector<string> v(N);
  for(auto &i:v)cin>>i;
  int mi=1e9;
  pair<int,int> best;
  for(int i=0;i<3;i++){
    int k=prova(i,v,0);
    if(k<mi){
      mi=k;
      best={0,i};
    }
  }
  for(int i=0;i<3;i++){
    int k=prova1(i,v,0);
    if(k<mi){
      mi=k;
      best={1,i};
    }
  }
  for(int i=0;i<3;i++){
    int k=prova2(i,v,0);
    if(k<mi){
      mi=k;
      best={2,i};
    }
  }
  for(int i=0;i<3;i++){
    int k=prova3(i,v,0);
    if(k<mi){
      mi=k;
      best={3,i};
    }
  }
  if(best.fi==0)prova(best.se,v,1);
  if(best.fi==1)prova1(best.se,v,1);
  if(best.fi==2)prova2(best.se,v,1);
  if(best.fi==3)prova3(best.se,v,1);

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}