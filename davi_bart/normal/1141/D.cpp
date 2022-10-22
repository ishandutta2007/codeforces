#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
vector<int> le[300];
vector<int> ri[300];
vector<pair<int,int> >sol;
vector<int> riml;
vector<int> rimr;
int tot=0;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    string l,r;
    cin>>l>>r;
    for(int i=0;i<N;i++){
      le[l[i]-'0'].push_back(i);
      ri[r[i]-'0'].push_back(i);
    }
    int pi='?'-'0';
    for(int i=0;i<300;i++){
      if(i==pi)continue;
      for(int j=0;j<min(le[i].size(),ri[i].size());j++){
        tot++;
        sol.push_back({le[i][j],ri[i][j]});
      }
      for(int j=min(le[i].size(),ri[i].size());j<max(le[i].size(),ri[i].size());j++){
        if(le[i].size()>ri[i].size()){
          riml.push_back(le[i][j]);
        }else{
          rimr.push_back(ri[i][j]);
        }
      }
    }
    int o=le[pi].size();
    int f=ri[pi].size();
    for(int i=0;i<min(le[pi].size(),rimr.size());i++){
      tot++;
      sol.push_back({le[pi][i],rimr[i]});
      o--;
    }
    for(int i=0;i<min(ri[pi].size(),riml.size());i++){
      tot++;
      sol.push_back({riml[i],ri[pi][i]});
      f--;
    }
    int p=min(o,f);
    for(int i=0;i<p;i++){
        tot++;
        sol.push_back({le[pi][le[pi].size()-o],ri[pi][ri[pi].size()-f]});
        f--;
        o--;
    }
    cout<<tot<<endl;
    for(int i=0;i<sol.size();i++){
      cout<<sol[i].first+1<<" "<<sol[i].second+1<<endl;
    }
    return 0;
}