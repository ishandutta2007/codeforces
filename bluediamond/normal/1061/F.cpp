#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long)(new char));

bool onpath(int a,int b,int c){
  cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
  string sol;
  cin>>sol;
  assert(sol=="Yes"||sol=="No");
  if(sol=="Yes"){
    return 1;
  }else{
    return 0;
  }
}

signed main() {
  int n,k,ninit;
  cin>>n>>k;
  ninit=n;
  vector<int> atlevel;
  atlevel.push_back(1);
  ninit-=1;
  while(ninit>0){
    int val=atlevel.back();
    atlevel.push_back(k*val);
    ninit-=atlevel.back();
  }
  assert(ninit==0);
  int maxcntnodes=2*((int)atlevel.size()-1)-1;
  vector<int> inside;
  vector<vector<int>> nec;
  int maxsz=0;
  for(int iter=1;iter<60;iter++) {

    int a=rng()%n+1;
    int b=rng()%n+1;
    inside.clear();
    for(int i=1;i<=n;i++){
      if(a==i||b==i) continue;
      if(onpath(a,i,b)){
        inside.push_back(i);
      }
    }
    maxsz=max(maxsz,(int)inside.size());
    if((int)inside.size()==maxcntnodes){
      nec.push_back(inside);
    }
  }
  vector<int> f(n+1,0);
  for(auto&v:nec){
    for(auto&x:v){
      assert(1<=x&&x<=n);
      f[x]++;
    }
  }
  vector<int> pot;
  for(int i=1;i<=n;i++){
    if(f[i]==(int)nec.size()){
      pot.push_back(i);
    }
  }
  assert((int)pot.size()==1||(int)pot.size()==3);
  if((int)pot.size()==3){
    int ind=-1;
    for(int i=0;i<3;i++){
      for(int j=i+1;j<3;j++){
        int k=3-i-j;
        if(onpath(pot[i],pot[k],pot[j])){
          assert(ind==-1);
          ind=k;
        }
      }
    }
    cout<<"! "<<pot[ind]<<endl;
    exit(0);
  }

  cout<<"! "<<pot[0]<<endl;
  return 0;
}