#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    if(N%4==2){
      cout<<1<<" B"<<endl;
      return 0;
    }
    int p=N/4*4+1+4;
    cout<<(p-N)%4<<" A"<<endl;
    return 0;
}