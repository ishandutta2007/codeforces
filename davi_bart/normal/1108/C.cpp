#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char> v,p,sol(3,0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      char a;
      cin>>a;
      v.push_back(a);
    }
    p.push_back('R');
    p.push_back('G');
    p.push_back('B');
    int mi=1000000;
    for(int i=0;i<7;i++){
      int tot=0;
      for(int j=0;j<N;j++){
        if(v[j]!=p[j%3])tot++;
      }
      if(tot<mi){
        mi=tot;
        sol[0]=p[0];sol[1]=p[1];sol[2]=p[2];
      }
      next_permutation(p.begin(),p.end());
    }
    cout<<mi<<endl;
    for(int i=0;i<N;i++){
      cout<<sol[i%3];
    }
		return 0;
}