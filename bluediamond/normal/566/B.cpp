#include <bits/stdc++.h>

bool home = 1;

using namespace std;

mt19937 rng((long long) (new char));
const int N=4*30000+7;
int n,a[N],b[N],c[N],v[N],nxt[N],point[N];
bool taken[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin>>n;


  for(int i=1;i<=n;i++){
    v[i]=4;
  }

  for(int i=0;i<=4*n+1;i++){
    nxt[i]=i+1;
  }

  for(int i=1;i<=4*n;i++){
    cin>>a[i]>>b[i]>>c[i];
    point[i]=i;
    if (c[i]==a[i]) {
      swap(b[i], c[i]);
    }
  }

  shuffle(point+1,point+4*n+1,rng);

  vector<int> sol;
  int found=0;

  while(found<4*n){
    int ant=0;
    for (int i=nxt[0];i<=4*n;i=nxt[i]){
      int old_ant=ant;
      ant=i;

      if(taken[i]){
        nxt[old_ant]=nxt[i];
        continue;
      }

      int x=a[point[i]];
      int y=b[point[i]];
      int z=c[point[i]];

      if(x==y&&y==z){
        if(v[x]+1<=9){
          found++;
          taken[i]=1;
          v[x]++;
          sol.push_back(point[i]);
        }
        continue;
      }

      if(x==y&&x!=z){
        if(v[z]+1<=9){
          found++;
          taken[i]=1;
          v[z]++;
          sol.push_back(point[i]);
        }
        continue;
      }
      if(x!=y&&y==z){
        if(v[x]-1>=0&&v[y]+2<=9){
          found++;
          taken[i]=1;
          v[x]--;
          v[y]+=2;
          sol.push_back(point[i]);
        }
        continue;
      }
      assert(x!=y);
      assert(x!=z);
      assert(y!=z);

      if(v[x]-1>=0&&v[y]+1<=9&&v[z]+1<=9){
        found++;
        taken[i]=1;
        v[x]--;
        v[y]++;
        v[z]++;
        sol.push_back(point[i]);
        continue;
      }

    }
  }
  cout<<"YES\n";
  for (auto &i:sol){
    cout<<i<<" ";
  }
  cout<<"\n";

}
/**
1 2 3
1 1 1
1 1 1
1 1 1
2 1 3
2 2 2
2 2 2
2 2 2
3 1 2
3 3 3
3 3 3
3 3 3

mereu se poate


a -> (b, c) =>

v[a] = v[a] - 1
v[b] = v[b] + 1
v[c] = v[c] + 1

**/