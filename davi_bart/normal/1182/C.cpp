#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> p;//parole
vector<pair<char,int> > v[1000010];//vocali in una parola
set<char> voc;
vector<pair<int,int> > cg;//coppie giuste
vector<pair<int,int> > cs;//coppie sbagliate;
vector<pair<pair<int,int>,pair<int,int> > > sol;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  voc.insert('a');voc.insert('e');voc.insert('i');voc.insert('o');voc.insert('u');
  int N;
  cin>>N;
  string h;
  for(int i=0;i<N;i++){
    cin>>h;
    p.push_back(h);
    int t=0;
    char last;
    for(int i=0;i<h.size();i++){
      if(voc.find(h[i])!=voc.end()){
        last=h[i];
        t++;
      }
    }
    v[t].push_back({last,i});
  }
  for(int i=0;i<1000010;i++){
    sort(v[i].begin(),v[i].end());
  }
  for(int i=0;i<1000010;i++){
    vector<int> spaiati;
    int j;
    for(j=1;j<v[i].size();j++){
      if(v[i][j].first==v[i][j-1].first){
            cg.push_back({v[i][j].second,v[i][j-1].second});
            j++;
            if(j==v[i].size()-1)spaiati.push_back(v[i][j].second);
      }else{
        if(j==v[i].size()-1)cs.push_back({v[i][j].second,v[i][j-1].second});
        else {
            spaiati.push_back(v[i][j-1].second);
            if(j==v[i].size()-1)spaiati.push_back(v[i][j].second);
        }
      }
    }
    for(int j=1;j<spaiati.size();j+=2)cs.push_back({spaiati[j],spaiati[j-1]});
  }
  for(int i=0;i<min(cg.size(),cs.size());i++){
    sol.push_back({{cs[i].first,cg[i].first},{cs[i].second,cg[i].second}});
  }
  if(cg.size()>cs.size()){
    for(int i=cs.size()+1;i<cg.size();i+=2){
      sol.push_back({{cg[i].first,cg[i-1].first},{cg[i].second,cg[i-1].second}});
    }
  }
  cout<<sol.size()<<endl;
  for(int i=0;i<sol.size();i++){
    int a=sol[i].first.first,b=sol[i].first.second,c=sol[i].second.first,d=sol[i].second.second;
    cout<<p[a]<<" "<<p[b]<<endl<<p[c]<<" "<<p[d]<<endl;
  }
  return 0;
}