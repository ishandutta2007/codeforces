#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().tempo_since_epoch().count());
int N;
vector<int> v;
int dist[2009][10];
vector<string> digit={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<int> dig;
int memo[2009][2009];
bool sol(int pos,int K){
  if(K<0)return 0;
  if(pos==v.size() && K==0)return 1;
  if(pos==v.size())return 0;
  if(memo[pos][K]!=-1)return memo[pos][K];
  memo[pos][K]=0;
  for(int i=dig.size()-1;i>=0;i--){
    bool x=sol(pos+1,K-dist[pos][i]);
    if(x){
      memo[pos][K]=x;
      break;
    }
  }
  return memo[pos][K];
}
void stampa(int pos,int K){
  if(pos==v.size())return ;
  for(int i=dig.size()-1;i>=0;i--){
    bool x=sol(pos+1,K-dist[pos][i]);
    if(x){
      cout<<i;
      stampa(pos+1,K-dist[pos][i]);
      return ;
    }
  }
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("output.txt","w",stdout);
		for(int i=0;i<digit.size();i++){
      int h=0;
      for(int j=0;j<digit[i].size();j++){
        h+=(1<<j)*(digit[i][j]-'0');
      }
      dig.push_back(h);
		}
		for(int i=0;i<2005;i++)fill(memo[i],memo[i]+2005,-1);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
      string k;
      cin>>k;
      int a=0;
      for(int j=0;j<k.size();j++){
        a+=(1<<j)*(k[j]-'0');
      }
      v.push_back(a);
      for(int j=0;j<dig.size();j++){
        if((v[i]&dig[j])!=v[i]){
          dist[i][j]=1e5;
          continue;
        }
        dist[i][j]=__builtin_popcount((v[i]^dig[j]));
      }
    }
    if(!sol(0,K)){
      cout<<-1;
      return 0;
    }
    stampa(0,K);
    return 0;
}