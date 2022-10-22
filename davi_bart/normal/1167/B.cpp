#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int>a;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  a.push_back(4);
  a.push_back(16);
  a.push_back(8);
  a.push_back(15);
  a.push_back(23);
  a.push_back(42);
  for(int i=0;i<4;i++){
    cout<<"? "<<1<<" "<<i+2<<endl;
    cout.flush();
    int o;
    cin>>o;
    p.push_back(o);
  }
  int primo;
  if(p[0]%16==0 && p[1]%16==0 && p[2]%16==0 && p[3]%16==0)primo=16;
  else if(p[0]%8==0 && p[1]%8==0 && p[2]%8==0 && p[3]%8==0)primo=8;
  else if(p[0]%4==0 && p[1]%4==0 && p[2]%4==0 && p[3]%4==0)primo=4;
  else if(p[0]%42==0 && p[1]%42==0 && p[2]%42==0 && p[3]%42==0)primo=42;
  else if(p[0]%23==0 && p[1]%23==0 && p[2]%23==0 && p[3]%23==0)primo=23;
  else if(p[0]%15==0 && p[1]%15==0 && p[2]%15==0 && p[3]%15==0)primo=15;
  cout<<"! "<<primo<<" "<<p[0]/primo<<" "<<p[1]/primo<<" "<<p[2]/primo<<" "<<p[3]/primo<<" ";
  for(int i=0;i<a.size();i++){
    if(a[i]!=primo && a[i]!=p[0]/primo && a[i]!=p[1]/primo && a[i]!=p[2]/primo && a[i]!=p[3]/primo){
      cout<<a[i];
      return 0;
    }
  }
	return 0;
}