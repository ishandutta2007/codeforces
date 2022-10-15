#include <bits/stdc++.h>

using namespace std;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s,t;
    cin>>t;
    assert((int)t.size()==n);
    while(!t.empty()){
      if(t.back()=='0'){
        t.pop_back();
        assert((int)t.size()>=2);
        int id=t[(int)t.size()-1]-'0'+10*(t[(int)t.size()-2]-'0');
        assert(10<=id&&id<=26);
        s+=(char)('a'+id-1);
        t.pop_back();
        t.pop_back();
      }else{
        int id=t[(int)t.size()-1]-'0';
        assert(1<=id&&id<=9);
        s+=(char)('a'+id-1);
        t.pop_back();
      }
    }
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
  }

}