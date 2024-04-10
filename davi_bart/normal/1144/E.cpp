#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int sol[201000];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    string a,b;
    cin>>a>>b;
    int riporto=0;
    for(int i=0;i<N;i++){
      sol[i]=a[i]+b[i]-'a'-'a';
    }
    for(int i=N-1;i>0;i--){
        if(sol[i]>25){sol[i]-=26;
        sol[i-1]++;
        }
    }
    for(int i=0;i<N;i++){
      char d=sol[i]/2+'a';
      cout<<d;
      if(sol[i]%2==1)sol[i+1]+=26;
    }
    return 0;
}