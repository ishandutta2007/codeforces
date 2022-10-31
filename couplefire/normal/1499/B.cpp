#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
string s;
cin>>s;
int t1=-1;
int t2=0;
for(int i=1;i<s.size();i++){
  if(s[i]=='1' and s[i-1]=='1'){
    t1++;
  }
  if(s[i]=='0' and s[i-1]=='0' and t1>-1){
  t2++;
  }
}
if(t2==0){
  cout<<"YES"<<endl;
}else {
  cout<<"NO"<<endl;
}
  }
}