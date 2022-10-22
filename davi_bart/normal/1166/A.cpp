#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int a[30];
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;cin>>N;
  for(int i=0;i<N;i++){
    string p;
    cin>>p;
    a[p[0]-'a']++;
  }
  int tot=0;
  for(int i=0;i<30;i++){
    int o=a[i]/2;
    tot+=o*(o-1)/2;
    o=a[i]-o;
    tot+=o*(o-1)/2;
  }
  cout<<tot;
	return 0;
}