#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
      int N;
      cin>>N;
      vector<int> p;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        p.push_back(a);
      }
      sort(p.begin(),p.end());
      reverse(p.begin(),p.end());
      int h=p[1];
      h--;
      cout<<min(h,N-2)<<endl;
    }
    return 0;
}