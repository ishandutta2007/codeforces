#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
int a[1000000],n,m,l[1000000],r[1000000];
vector<tuple<int,int,int>>vec;
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>l[i]>>r[i];
    vec.push_back(make_tuple(r[i]-l[i]+1,l[i],r[i]));
  }
  sort(vec.begin(),vec.end());
  int minx=get<0>(vec[0]);
  cout<<minx<<endl;
  for(int i=1;i<=n;i++){
    if(i>=2)cout<<' ';
    cout<<i%minx;
  }
  cout<<endl;
  return 0;
}