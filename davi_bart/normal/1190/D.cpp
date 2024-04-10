#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
  int x,y;
};
vector<point> p;
int fatti[450];
vector<int> sq[450];
unordered_map<int,bool> vis;
vector<int> ordinax;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      point s;
      cin>>s.x>>s.y;
      p.push_back(s);
      ordinax.push_back(s.x);
    }
    sort(p.begin(),p.end(),[](point a,point b){
      if(a.y==b.y)return a.x<b.x;
      return a.y>b.y;
    });
    sort(ordinax.begin(),ordinax.end());
    ordinax.resize(unique(ordinax.begin(),ordinax.end())-ordinax.begin());
    int rad=sqrt(ordinax.size())+1;
    int gruppo=0,l=rad;
    for(int i=0;i<ordinax.size();i++){
      if(l==0){
        l=rad;
        gruppo++;
      }
      l--;
      sq[gruppo].push_back(ordinax[i]);
    }
    int tot=0;
    ll sol=0;
    for(int i=0;i<p.size();){
      int prec=-1,Y=p[i].y,ultimo;
      int o=i;
      while(p[o].y==Y){
        if(vis[p[o].x]==0)tot++;
        o++;
      }
      while(p[i].y==Y){
        int prima=0;
        int X=p[i].x;
        for(int j=0;j<450;j++){
          if(sq[j].back()<X){
            prima+=fatti[j];
            continue;
          }
          if(vis[X]==0)fatti[j]++;
          for(int h=0;h<sq[j].size();h++){
            if(sq[j][h]>=X)break;
            if(vis[sq[j][h]])prima++;
          }
          break;
        }
        ultimo=prima;
        prima=prima-prec;
        prec=ultimo;
        vis[X]=1;
        //cout<<prima<<" "<<tot<<" "<<ultimo<<endl;
        sol+=(ll)(prima)*(ll)(tot-ultimo);
        i++;
        //cout<<sol<<endl;
      }
    }
    cout<<sol;
    return 0;
}