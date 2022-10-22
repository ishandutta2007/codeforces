#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool p[2][100010];
set<pair<int,int> >block;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N>>M;
		for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      a--;
      p[a][b]=!p[a][b];
      if(p[a][b]){
        if(a==0){
          if(p[1][b-1])block.insert({b,b-1});
          if(p[1][b])block.insert({b,b});
          if(p[1][b+1])block.insert({b,b+1});
        }else{
          if(p[0][b-1])block.insert({b-1,b});
          if(p[0][b])block.insert({b,b});
          if(p[0][b+1])block.insert({b+1,b});
        }
      }else{
        if(a==0){
          if(p[1][b-1])block.erase({b,b-1});
          if(p[1][b])block.erase({b,b});
          if(p[1][b+1])block.erase({b,b+1});
        }else{
          if(p[0][b-1])block.erase({b-1,b});
          if(p[0][b])block.erase({b,b});
          if(p[0][b+1])block.erase({b+1,b});
        }
      }
        if(block.size()==0)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
		}
    return 0;
}