#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;// 0 blu ;  1 rosso
bool sol[200010];
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  string a;
  cin>>a;
  int ar=0,cr=0,ab=0,cb=0;
  for(int i=0;i<N;i++){
    if(a[i]=='('){
      if(ar>ab){
        sol[i]=0;
        ab++;
      }else{
        sol[i]=1;
        ar++;
      }
    }else{
      if(ar>ab){
        sol[i]=1;
        ar--;
      }else{
        sol[i]=0;
        ab--;
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<sol[i];
  }
  cout.flush();
	return 0;
}