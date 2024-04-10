#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> incr;
vector<int> decr;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      int b;
      cin>>b;
      a.push_back(b);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<N;i++){
      if(incr.size()==0 || incr.back()!=a[i])incr.push_back(a[i]);
      else if(decr.size()==0 || decr.back()!=a[i])decr.push_back(a[i]);
      else{
        cout<<"NO";
        return 0;
      }
    }
    cout<<"YES"<<endl;
    reverse(decr.begin(),decr.end());
    cout<<incr.size()<<endl;
    for(int i=0;i<incr.size();i++){
      cout<<incr[i]<<" ";
    }
    cout<<endl<<decr.size()<<endl;
    for(int i=0;i<decr.size();i++){
      cout<<decr[i]<<" ";
    }
    return 0;
}