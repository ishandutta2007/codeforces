#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int N;
    cin>>N;
    int pos;
    int a;
    for(int i=0;i<N;i++){
      cin>>a;
      v.push_back(a);
      if(a==N)pos=i;
    }
    for(int i=1;i<pos;i++){
      if(v[i]<v[i-1]){
        cout<<"NO";
        return 0;
      }
    }
    for(int i=pos;i<N-1;i++){
      if(v[i]<v[i+1]){
        cout<<"NO";
        return 0;
      }
    }
    cout<<"YES";
    return 0;
}