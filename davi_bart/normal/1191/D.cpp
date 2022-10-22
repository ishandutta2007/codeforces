#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>p;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int a;
    for(int i=0;i<N;i++){
      cin>>a;
      p.push_back(a);
    }
    sort(p.begin(),p.end());
    int coppie=0;
    int o=-1;
    for(int i=1;i<N;i++){
      if(p[i]==p[i-1]){
        o=i-2;
        coppie++;
        if(p[i]==0){
          cout<<"cslnb"<<endl;
          return 0;
        }
      }
    }
    if(coppie>1 || (o>=0 && p[o]==p[o+1]-1)){
      cout<<"cslnb"<<endl;
      return 0;
    }
    int mosse=0;
    for(int i=0;i<p.size();i++){
      mosse+=p[i]-i;
    }
    if(mosse%2==0)cout<<"cslnb"<<endl;
    else cout<<"sjfnb"<<endl;
    return 0;
}