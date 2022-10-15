#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)5e5+7;
int n;
int c[N];
int ord[N];
int lcp[N];
int bal[N];
string s;

struct T{
  int c1;
  int c2;
  int i;
};

bool operator < (T a,T b){
  if(a.c1!=b.c1) return a.c1<b.c1;
  return a.c2<b.c2;
}

bool operator == (T a,T b){
  return a.c1==b.c1&&a.c2==b.c2;
}

int until[N];
vector<int> w[2*N];

int getcnt(int x,int pref){
  x+=N;
  int l=0,r=(int)w[x].size()-1,sol=0;
  while(l<=r){
    int m=(l+r)/2;
    if(w[x][m]<=pref){
      sol=m+1;
      l=m+1;
    }else{
      r=m-1;
    }
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen ("input.txt","r",stdin);

  cin>>n>>s;
  s+="$";

  {
    assert((int)s.size()==n+1);
    for(int i=0;i<n;i++){
      assert(s.back()<s[i]);
    }
  }


  {
    for(int i=0;i<(int)s.size();i++){
      if(s[i]=='('){
        c[i]=1;
      }
      if(s[i]==')'){
        c[i]=2;
      }
      if(s[i]=='$'){
        c[i]=0;
      }
    }
    int p=0;
    for(int x=0;x<=2;x++){
      for(int i=0;i<(int)s.size();i++){
        if(c[i]==x){
          ord[p++]=i;
        }
      }
    }
    assert(p==(int)s.size());

    {
      int len=1;
      while(len<=(int)s.size()){
        vector<T> v;
        for(int i=0;i<(int)s.size();i++){
          v.push_back({c[i],c[(i+len)%(int)s.size()],i});
        }
        sort(v.begin(),v.end());
        assert((int)v.size()==(int)s.size());
        for(int i=0;i<(int)s.size();i++){
          ord[i]=v[i].i;
        }
        int comps=0;
        c[ord[0]]=0;
        for(int i=1;i<(int)s.size();i++){
          comps+=1-(v[i]==v[i-1]);
          c[ord[i]]=comps;
        }
        len*=2;
      }
    }
    {
      int k=0;
      for(int j=0;j<(int)s.size();j++){
        int i=c[j];
        //k=0;
        if(i<(int)s.size()-1){
          int x=ord[i];
          int y=ord[i+1];
          while(x+k<(int)s.size()&&y+k<(int)s.size()&&s[x+k]==s[y+k]){ /// opt
            k++;
          }
          lcp[i]=k;
          if(k>0) k--;
        }else{
          k=0;
        }

      }
    }
  }
  for(int i=1;i<=n;i++){
    bal[i]=bal[i-1];
    if(s[i-1]=='(') bal[i]++; else {
      assert(s[i-1]==')');
      bal[i]--;
    }
  }
  for(int i=0;i<=n;i++){
    w[bal[i]+N].push_back(i);
  }

  vector<int> stk;


  for(int l=n;l>=0;l--){
    while(!stk.empty()&&bal[l]<=bal[stk.back()]) stk.pop_back();
    if(stk.empty()) until[l]=n;
    else until[l]=stk.back()-1;
    stk.push_back(l);
  }

  ll sol=0;

  for(int l=1;l<=n;l++){
    int start=lcp[c[l-1]]+l;
    int stop=until[l-1];

    if(start>stop) continue;
    sol+=getcnt(bal[l-1],stop)-getcnt(bal[l-1],start-1);
  }
  cout<<sol<<"\n";


  return 0;
}