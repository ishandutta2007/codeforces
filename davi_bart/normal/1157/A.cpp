#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,bool> vis;
int f(int N){
    N++;
    while(N%10==0)N/=10;
    return N;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    int tot=1;
    vis[N]=1;
    while(1){
      N=f(N);
      if(vis[N]==1)break;
      vis[N]=1;
      tot++;
    }
    cout<<tot;
    return 0;
}