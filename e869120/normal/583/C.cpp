#include<iostream>
#include<algorithm>
#include<functional>
#include<map>
#include<vector>
using namespace std;
int n,a[300000],p[600][600];
map<int,int>M;vector<int>vec;
int gcd(int a,int b){
  if(b==0)return a;
  return gcd(b,a%b);
}
int main(){
  cin>>n;
  for(int i=0;i<n*n;i++){
    cin>>a[i];M[a[i]]++;
    if(M[a[i]]==1)vec.push_back(a[i]);
  }
  sort(vec.begin(),vec.end(),greater<int>());
  int cnt=0;
  for(int i=0;i<n;i++){
    p[i][i]=vec[cnt];M[vec[cnt]]--;
    for(int j=0;j<i;j++){
      p[i][j]=gcd(p[i][i],p[j][j]);
      M[p[i][j]]--;
    }
    for(int j=0;j<i;j++){
      p[j][i]=gcd(p[i][i],p[j][j]);
      M[p[j][i]]--;
    }
    while(cnt<(int)vec.size() && M[vec[cnt]]==0){cnt++;}
  }
  for(int i=0;i<n;i++){
    if(i)cout<<' ';
    cout<<p[i][i];
  }
  cout<<endl;
  return 0;
}