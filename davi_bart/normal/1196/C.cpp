#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
    int Xma=100000,Xmi=-100000,Yma=100000,Ymi=-100000;
      int N;
      cin>>N;
      for(int i=0;i<N;i++){
        int x,y,sx,giu,dx,su;
        cin>>x>>y>>sx>>giu>>dx>>su;
        if(sx==0)Xmi=max(Xmi,x);
        if(dx==0)Xma=min(Xma,x);
        if(su==0)Ymi=max(Ymi,y);
        if(giu==0)Yma=min(Yma,y);
      }
      if(Xmi<=Xma && Ymi<=Yma){
        cout<<1<<" "<<Xmi<<" "<<Ymi<<endl;
      }else{
        cout<<0<<endl;
      }
    }
    return 0;
}