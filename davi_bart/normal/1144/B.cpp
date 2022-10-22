#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> pari;
vector<int> dispari;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      if(a%2==0)pari.push_back(a);
      else dispari.push_back(a);
    }
    sort(pari.begin(),pari.end());
    reverse(pari.begin(),pari.end());
    sort(dispari.begin(),dispari.end());
    reverse(dispari.begin(),dispari.end());
    if(pari.size()>dispari.size()){
      long long int tot=0;
      for(int i=dispari.size()+1;i<pari.size();i++){
        tot+=pari[i];
      }
      cout<<tot;
    }else{
      long long int tot=0;
      for(int i=pari.size()+1;i<dispari.size();i++){
        tot+=dispari[i];
      }
      cout<<tot;
    }
    return 0;
}