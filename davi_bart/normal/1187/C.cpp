#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sortare[1009]; //1 se il val deve essere >= del prec
int main(){
  //freopen("ciao.txt", "r", stdin);
  //freopen("sol.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N,M;
  cin>>N>>M;
  vector<pair<pair<int,int>,int> >p;
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    p.push_back({{a,b},c});
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  for(int i=0;i<M;i++){
    int a=p[i].first.first;
    int b=p[i].first.second;
    int c=p[i].second;
    if(a){
      for(int i=b+1;i<=c;i++)sortare[i]=1;
    }else{
      for(int i=b+1;i<=c;i++){
        if(sortare[i]==0)break;
        else if(i==c){
          cout<<"NO";
          return 0;
        }
      }
    }
  }
  cout<<"YES"<<endl;
  int prec=1000000;
  cout<<prec<<" ";
  for(int i=2;i<=N;i++){
    if(sortare[i]){
      prec=1000000;
    }else{
      prec--;
    }
    cout<<prec<<" ";
  }
  return 0;
}