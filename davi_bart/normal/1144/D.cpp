#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int volte[300000];
unordered_map<int,int> o;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    int pos=0;
    a.push_back(-100);
    for(int i=1;i<=N;i++){
      int b;
      cin>>b;
      a.push_back(b);
      volte[b]++;
      if(volte[b]>volte[pos]){
        pos=b;
      }
      o[b]=i;
    }
    cout<<N-volte[pos]<<endl;
    int p=o[pos];
    for(int i=p+1;i<=N;i++){
      if(a[i]==pos)continue;
      if(a[i]>pos)cout<<2<<" "<<i<<" "<<i-1<<endl;
      else cout<<1<<" "<<i<<" "<<i-1<<endl;
    }
    for(int i=p-1;i>0;i--){
      if(a[i]==pos)continue;
      if(a[i]>pos)cout<<2<<" "<<i<<" "<<i+1<<endl;
      else cout<<1<<" "<<i<<" "<<i+1<<endl;
    }
    return 0;
}