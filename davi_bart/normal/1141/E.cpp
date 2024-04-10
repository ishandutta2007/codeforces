#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
vector<int> d;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long int H,N;
    long long int sol;
    cin>>H>>N;
    long long int mi=H;
    long long int o;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      d.push_back(a);
      mi+=a;
      if(mi<o)o=mi;
      if(o<=0){
        cout<<i+1;
        return 0;
      }
    }
    if(H-mi<=0){
      cout<<-1;
      return 0;
    }
    long long int j=H;
    long long int dif=H-o;
    H-=dif;
    long long int diff=j-mi;
    if(H%diff==0){
        sol=N*((H)/diff);
        H=dif;
    }else{
        sol=N*(H/diff)+N;
        H=H-(H/diff*diff+diff)+dif;
    }
    for(int i=0;i<N;i++){
      H+=d[i];
      if(H<=0){
        cout<<sol+i+1;
        return 0;
      }
    }
    return 0;
}