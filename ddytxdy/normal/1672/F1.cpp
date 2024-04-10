#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int T,n,a[N],p[N];
vector<int>v[N];
bool cmp(int x,int y){
  return v[x].size()>v[y].size();
}
void solve(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  for(int i=1;i<=n;i++)
    v[a[i]].pb(i);
  for(int i=1;i<=n;i++)
    p[i]=i;
  sort(p+1,p+n+1,cmp);
  for(int i=1;i<=v[p[1]].size();i++){
    int j=1;
    while(i<=v[p[j+1]].size()){
      a[v[p[j+1]][i-1]]=p[j];
      j++;
    }
    a[v[p[1]][i-1]]=p[j];
  }
  for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
  puts("");
  for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}