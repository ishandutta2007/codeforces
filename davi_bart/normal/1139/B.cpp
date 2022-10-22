#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
int a[200010];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      cin>>a[i];
    }
    long long int tot=0;
    int prec=1000000010;
    for(int i=N-1;i>=0;i--){
      if(prec==0)break;
      tot+=min(prec-1,a[i]);
      prec=min(prec-1,a[i]);
    }
    cout<<tot;
    return 0;
}