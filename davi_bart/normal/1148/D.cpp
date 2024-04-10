#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int> > su;
vector<pair<pair<int,int>,int> > giu;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int N;
    cin>>N;
    int a,b;
    for(int i=0;i<N;i++){
      cin>>a>>b;
      if(a>b)giu.push_back({{b,a},i+1});
      else su.push_back({{b,a},i+1});
    }
    cout<<max(su.size(),giu.size())<<endl;
    if(su.size()>giu.size()){
      sort(su.begin(),su.end());
      for(int i=su.size()-1;i>=0;i--){
        cout<<su[i].second<<" ";
      }
    }else{
      sort(giu.begin(),giu.end());
      for(int i=0;i<giu.size();i++){
        cout<<giu[i].second<<" ";
      }
    }
    return 0;
}