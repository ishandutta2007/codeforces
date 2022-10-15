#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home = 1;

const int N=(int)1e5+7;
vector<int> d[N];
int cnt[8];
vector<int> divis;
vector<int> nw;

void addToDivis(int x){
  nw.clear();
  int i=0,j=0;
  while(i<(int)divis.size()&&j<(int)d[x].size()){
    if(divis[i]==d[x][j]) {
      nw.push_back(divis[i++]);
      j++;
    }else{
      if(divis[i]<d[x][j]){
        nw.push_back(divis[i++]);
      }else{
        nw.push_back(d[x][j++]);
      }
    }
  }

  while(i<(int)divis.size()){
    nw.push_back(divis[i++]);
  }
  while(j<(int)d[x].size()){
    nw.push_back(d[x][j++]);
  }
  divis=nw;
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

  for(int i=1;i<N;i++){
    for(int j=i;j<N;j+=i)d[j].push_back(i);
  }

  int tests;
  cin>>tests;

  for(int tc=1;tc<=tests;tc++){
    int a,b,c;
    cin>>a>>b>>c;
    divis=d[a];
    addToDivis(b);
    addToDivis(c);
    for(int i=0;i<8;i++) cnt[i]=0;
    for(int i=0;i<(int)divis.size();i++){
      int mask=0;
      if(a%divis[i]==0) mask+=1;
      if(b%divis[i]==0) mask+=2;
      if(c%divis[i]==0) mask+=4;
      cnt[mask]++;
    }
    vector<vector<int>> needs;
    needs.push_back({1,2,4});
    needs.push_back({1,4,1});
    needs.push_back({2,1,4});
    needs.push_back({2,4,1});
    needs.push_back({4,1,2});
    needs.push_back({4,2,1});
    set<vector<int>> s;
    ll sol=0;
    for(int i=0;i<8;i++){
      for(int j=i;j<8;j++){
        for(int k=j;k<8;k++){
          bool isok=0;

          for(auto&v:needs){
            bool oknow=1;
            oknow&=((i&(v[0]))>0);
            oknow&=((j&(v[1]))>0);
            oknow&=((k&(v[2]))>0);
            if(oknow)isok=1;
          }

          if((i|j|k)!=7)continue;
          if((i==j||j==k)&&j==1)continue;
          if((i==j||j==k)&&j==2)continue;
          if((i==j||j==k)&&j==4)continue;

          if(i==j&&j==k){
            sol+=(ll)cnt[i]*(cnt[i]+1)*(cnt[i]+2)/6;
            continue;
          }
          if(i==j){
            sol+=(ll)cnt[i]*(cnt[i]+1)*cnt[k]/2;
            continue;
          }
          if(j==k){
            sol+=(ll)cnt[i]*(cnt[j])*(cnt[j]+1)/2;
            continue;
          }
          sol+=(ll)cnt[i]*cnt[j]*cnt[k];
        }
      }
    }
    cout<<sol<<"\n";
  }


  return 0;
}