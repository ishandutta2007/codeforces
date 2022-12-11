#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
vector<int>v[N];
int T,n,m,p1,p2;bool fl,ban[N];
void solve(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)ban[i]=0;
  p1=p2=-1;fl=1;
  for(int i=0;i<n;i++){
    v[i].resize(m);
    int pp1=-1,pp2=-1;
    for(int j=0;j<m;j++){
      scanf("%d",&v[i][j]);
      if(j&&v[i][j]<v[i][j-1]){
        if(pp1==-1)pp1=j-1;
        else if(pp2==-1)pp2=j;
        else fl=0;
      }
    }
    if(pp1!=-1&&pp2==-1){
      pp2=pp1+1;
      while(pp2+1<m&&v[i][pp2+1]==v[i][pp2])pp2++;
      while(pp1>0&&v[i][pp1-1]==v[i][pp1])pp1--;
    }
    if(p1!=-1&&pp1!=-1&&(p1!=pp1||p2!=pp2))
      fl=0;
    if(pp1!=-1)p1=pp1,p2=pp2;
  }
  if(!fl){puts("-1");return;}
  if(p1!=-1){
    for(int i=0;i<n;i++){
      swap(v[i][p1],v[i][p2]);
      for(int j=1;j<m;j++)
        if(v[i][j]<v[i][j-1])fl=0;
    }
    if(!fl)puts("-1");
    else printf("%d %d\n",p1+1,p2+1);
  }
  else puts("1 1");
}
int main(){
  // freopen("in.txt","r",stdin);
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}