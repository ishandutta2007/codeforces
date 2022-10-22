#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
char a[55][55];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    int n1=0,n2=0;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      if(a==1)n1++;
      else n2++;
    }
    if(n2)cout<<2<<" ";
    if(n1)cout<<1<<" ";
    for(int i=0;i<n2-1;i++)cout<<2<<" ";
    for(int i=0;i<n1-1;i++)cout<<1<<" ";
    return 0;
}