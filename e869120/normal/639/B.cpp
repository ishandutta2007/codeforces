#include<iostream>
#include<vector>
using namespace std;
int n,d,t;vector<int>vec;
int main(){
  cin>>n>>d>>t;int cnt=1;
  int s=d-t;
  if(n==2 && d==1){cout<<"1 2"<<endl;return 0;}
  if(d>t*2 || d<t || d==1 || d==n){cout<<"-1"<<endl;return 0;}
  for(int i=0;i<d+1;i++){
    if(i!=s){cnt++;vec.push_back(cnt);}
    if(i==s){vec.push_back(1);}
  }
  for(int i=0;i<vec.size()-1;i++){
    cout<<vec[i]<<' '<<vec[i+1]<<endl;
  }
  for(int i=0;i<n-vec.size();i++){
    cout<<vec[vec.size()/2]<<' '<<i+vec.size()+1<<endl;
  }
  return 0;
}