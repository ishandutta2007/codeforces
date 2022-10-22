#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> p;
vector<int> somma;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int o;
    cin>>o;
    p.push_back(o);
  }
  somma.push_back(0);
  somma.push_back(p[0]);
  for(int i=1;i<N;i++){
    somma.push_back(somma[i]+p[i]);
  }
  int Q;
  cin>>Q;
  int a,b;
  for(int i=0;i<Q;i++){
    cin>>a>>b;
    int s=somma[b]-somma[a-1];
    cout<<s/10<<endl;
  }
  return 0;
}