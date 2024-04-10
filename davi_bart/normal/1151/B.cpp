#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
int a[601][601];
int riga[601];
vector<int> sol;
int N,M;
bool trova(int o){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if((a[i][j]&o)>0){
        if(riga[i]==0)riga[i]=1;
        if(riga[i]==2)riga[i]=3;
      }else{
        if(riga[i]==0)riga[i]=2;
        if(riga[i]==1)riga[i]=3;
      }
    }
  }
  int tot=0;
  int tot2=0;
  for(int i=0;i<N;i++){
    if(riga[i]==1){
      tot++;
    }
    if(riga[i]==3 || riga[i]==1){
      tot2++;
    }
  }
  bool k=0;
  if(tot2==0 || (tot2==tot && tot%2==0))return 0;
  if(tot%2==1)k=1;
  for(int i=0;i<N;i++){
    if(riga[i]==1 || riga[i]==2){
      sol.push_back(0);
      continue;
    }
    for(int j=0;j<M;j++){
      if(k==0){
        if((a[i][j]&o)>0){
          sol.push_back(j);
          k=1;
          break;
        }
      }else{
        if((a[i][j]&o)==0){
          sol.push_back(j);
          break;
        }
      }
    }
  }
  return 1;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin>>a[i][j];
      }
    }
    for(int i=0;i<20;i++){
      fill(riga,riga+600,0);
      int p=(1<<i);
      if(trova(p)==0){
        continue;
      }else{
        cout<<"TAK"<<endl;
        for(int j=0;j<sol.size();j++){
          cout<<sol[j]+1<<" ";
        }
        return 0;
      }
    }
    cout<<"NIE";
    return 0;
}