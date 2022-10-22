#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int> > pers;
vector<pair<long long int,int> > diss;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      long long int a,b;
      cin>>a>>b;
      pers.push_back({a,b});
      long long int s=b-a;
      diss.push_back({s,i});
    }
    sort(diss.begin(),diss.end());
    long long int tot=0;
    for(int i=0;i<N;i++){
      int j=diss[i].second;
      tot+=(pers[j].first*i)+(pers[j].second*(N-i-1));
    }
    cout<<tot;
    return 0;
}