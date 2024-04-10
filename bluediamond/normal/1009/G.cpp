#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home = 1;
bool wannap = 0;

const int N=(int)1e5+7;
int f[6],cnt[1<<6];
int maskrestr[N];

bool isok(int n){
  for(int mask=0;mask<(1<<6);mask++){
    int a=0,b=0;
    for(int i=0;i<6;i++){
      if(mask&(1<<i)){
        a+=f[i];
      }
    }
    for(int m=0;m<(1<<6);m++){
      if((m&mask)>0){
        b+=cnt[m];
      }
    }
    if(a>b) return 0;
  }
  return 1;
}

void add(int i,int sgn){
  cnt[maskrestr[i]]+=sgn;
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  wannap=0;


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int n;

  {
    string chars;
    cin>>chars;
    n=(int)chars.size();
    for(auto&ch:chars){
      f[ch-'a']++;
    }
  }

  for(int i=1;i<=n;i++){
    maskrestr[i]=(1<<6)-1;
  }
  int restr;
  cin>>restr;
  while(restr--){
    int i;
    cin>>i;
    i=n+1-i;
    string s;
    cin>>s;
    maskrestr[i]=0;
    for(auto&ch:s){
      int id=ch-'a';
      maskrestr[i]|=(1<<id);
    }
  }
  for(int i=1;i<=n;i++){
    add(i,+1);
  }

  if(home&&wannap) {
    for(int i=1;i<=n;i++){
      for(int j=0;j<6;j++){
        if(maskrestr[i]&(1<<j)){
          cout<<"1";
        }else{
          cout<<"0";
        }
      }
      cout<<"\n";
    }
  }

  if(!isok(n)){
    cout<<"Impossible\n";
    return 0;
  }
  for(int i=n;i>=1;i--){
    int w=-1;
    add(i,-1);
    for(int x=0;x<6;x++){
      if(f[x]&&(maskrestr[i]&(1<<x))>0){
        f[x]--;
        bool ok=isok(i-1);
        f[x]++;
        if(ok){
          w=x;
          break;
        }
      }
    }
    if(w==-1){
      cout<<"\nlol\n";
      exit(0);
    }
    assert(w!=-1);
    f[w]--;

    cout<<(char)('a'+w);
  }
  cout<<"\n";




  return 0;
}