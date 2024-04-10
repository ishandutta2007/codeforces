#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<char>sol;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      v.push_back(a);
    }
    int sx=0,dx=N-1;
    int prec=-10000000;
    while(sx<=dx){
      if(v[sx]>prec){
        if(v[dx]<prec || v[dx]>v[sx]){
          sx++;
          sol.push_back('L');
          prec=v[sx-1];
        }else{
          prec=v[dx];
          sol.push_back('R');
          dx--;
        }
      }else if(v[dx]>prec){
        prec=v[dx];
        sol.push_back('R');
        dx--;
      }else break;
    }
    cout<<sol.size()<<endl;
    for(int i=0;i<sol.size();i++){
        cout<<sol[i];
    }
    return 0;
}