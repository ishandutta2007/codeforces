#include <bits/stdc++.h>
using namespace std;

struct hash_pair{
  template <class T1, class T2>
  size_t operator() (const pair<T1, T2> &p) const{
    auto h1 = hash<T1>{}(p.first);
    auto h2 = hash<T2>{}(p.second);
    return h1^h2;
  }
};

int main() {
  int n;
  cin >> n;
  unordered_map<pair<int, char>, vector<string>, hash_pair> sameend;
  unordered_map<int, vector<string>> samenum;
  unordered_map<string, int> num;
  for(int i = 0; i<n; i++){
    string s;
    cin >> s;
    int t = 0;
    char end;
    for(int k = 0; k<s.size(); k++){
      if(s[k] == 'a' ||
         s[k] == 'e' ||
         s[k] == 'i' ||
         s[k] == 'o' ||
         s[k] == 'u'){
           ++t;
           end = s[k];
         }
    }
    num[s] = t;
    sameend[make_pair(t, end)].push_back(s);
  }
  for(auto i : sameend){
    if(i.second.size() %2 == 1) samenum[i.first.first].push_back(i.second.back());
  }
  vector<pair<string, string>> rel;
  vector<pair<string, string>> rer;
  for(auto i : sameend){
    for(int it = 1; it < i.second.size(); it+=2){
      rer.push_back(pair<string, string>(i.second[it-1], i.second[it]));
    }
  }
  for(auto i : samenum){
    for(int it = 1; it < i.second.size(); it+=2){
      rel.push_back(pair<string, string>(i.second[it-1], i.second[it]));
    }
  }  
  cout << ((rel.size() >= rer.size()) ? rer.size() : rel.size() + (rer.size()-rel.size())/2) << endl;
  int itl= 0;
  int itr = 0;
  while(itl < rel.size() && itr < rer.size()){
    cout << rel[itl].first << " " << rer[itr].first << endl;
    cout << rel[itl].second << " " << rer[itr].second << endl;
    itl++;
    itr++;
  }
  ++itr;
  while(itr < rer.size()){
    cout << rer[itr-1].first << " " << rer[itr].first << endl;
    cout << rer[itr-1].second << " " << rer[itr].second << endl;
    itr += 2;
  }
}