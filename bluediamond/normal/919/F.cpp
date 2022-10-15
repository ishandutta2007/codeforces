#include <bits/stdc++.h>

using namespace std;

bool home = 1;


const int N=495;
const int M=5833;
int has[N][5];
int current[N];
int _super_secret_inv_[M];
int _super_secret_variable_;

int getInv(int Hash){
  int value=_super_secret_inv_[Hash];
  return value-1;
}

int getHash(int index){
  return has[index][1]+9*(has[index][2]+9*(has[index][3]+9*has[index][4]));
}

void gen(int Rem,int S){
  int Hash=current[1]+9*(current[2]+9*(current[3]+9*current[4]));
  for(int i=1;i<=4;i++){
    has[_super_secret_variable_][i]=current[i];
  }
  _super_secret_inv_[Hash]=++_super_secret_variable_;
  if(!Rem){
    return;
  }
  for(int x=S;x<=4;x++){
    current[x]++;
    gen(Rem-1,x);
    current[x]--;
  }
}

int _merge(int code1,int code2){
  assert(0<=code1&&code1<N);
  assert(0<=code2&&code2<N);
  return code1*N+code2;
}

vector<int> getTransitions(int code1,int code2){
  int z;
  vector<int> all;
  for(int x=1;x<=4;x++){
    for(int y=1;y<=4;y++){
      if(has[code1][x]&&has[code2][y]){
        z=(x+y)%5;
        has[code1][x]--;
        has[code1][z]++;
        int C=getInv(getHash(code1));
        all.push_back(_merge(code2,C));
        has[code1][x]++;
        has[code1][z]--;
      }
    }
  }
  return all;
}

vector<int> g[N*N];
vector<int> ginv[N*N];
int type[N*N];

int getDataPack(int state){
  bool has0=0;
  for(auto&x:g[state]){
    if(type[x]==-1) return 1;
    has0|=(type[x]==0);
  }
  if(has0) return 0;
  return -1;
}

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

  gen(8,1);
  assert(_super_secret_variable_==N);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int C=_merge(i,j);
      g[C]=getTransitions(i,j);
      for(auto&k:g[C]){
        ginv[k].push_back(C);
      }
    }
  }

  queue<int> Q;

  for(int i=0;i<N;i++){
    for(int j=(i==0);j<N;j++){
      assert(i+j>0);
      int c=_merge(i,j);
      if(i==0){
        type[c]=+1;
        Q.push(c);
      }
      if(j==0){
        type[c]=-1;
        Q.push(c);
      }
    }
  }

  while(!Q.empty()){
    int c=Q.front();
    Q.pop();
    for(auto&I:ginv[c]){
      int z=getDataPack(I);
      if(z!=type[I]){
        type[I]=z;
        Q.push(I);
      }
    }
  }

  int q;
  cin>>q;
  while(q--){
    vector<int> f1(5,0),f2(5,0);
    int who;
    cin>>who;
    for(int i=0;i<8;i++) {int x;cin>>x;f1[x]++;}
    for(int i=0;i<8;i++) {int x;cin>>x;f2[x]++;}
    int code1=f1[1]+9*(f1[2]+9*(f1[3]+9*f1[4]));
    int code2=f2[1]+9*(f2[2]+9*(f2[3]+9*f2[4]));
    code1=getInv(code1);
    code2=getInv(code2);
    if(who){
      swap(code2,code1);
    }
    int c=_merge(code1,code2);
    if(type[c]==0){
      cout<<"Deal\n";
      continue;
    }else{
      int x=type[c];
      if(who) x*=-1;
      if(x==+1){
        cout<<"Alice\n";
      }else{
        cout<<"Bob\n";
      }
    }
  }

  return 0;
}