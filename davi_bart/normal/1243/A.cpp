#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      int N;
      cin>>N;
      vector<int> v;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
      }
      sort(v.begin(),v.end(),greater<int>());
      bool p=0;
      for(int i=0;i<N;i++){
        if(i+1>v[i]){
            cout<<i<<endl;
            p=1;
            break;
        }
      }
      if(!p)cout<<N<<endl;
    }
		return 0;
}