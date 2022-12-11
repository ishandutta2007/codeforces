#include<bits/stdc++.h>
using namespace std;
int n,m,P[2333],C[2333],pc,l,r;
int find(int x,int w){
//    cerr<<x<<":::"<<w<<endl;
    if(x>pc)return l<=w;
    int c=0;
    for(int i=0;i<=C[x];++i,w*=P[x]) c+=find(x+1,w);
    return c;    
}
int main(){
    int t; cin>>t; while(t--){
        long long ans=0;
        cin>>l>>r;
        int len=r-l+1; ans=len*(len-1ll)*(len-2)/6;
        for(int i=l+2;i<=r;++i){
            int x=i; pc=0;
            for(int p=2;p*p<=x;++p) if(x%p==0){
                //cerr<<i<<' '<<p<<endl;
                P[++pc]=p; C[pc]=0;
                while(x%p==0)x/=p,C[pc]++;
            }
            if(x>1)P[++pc]=x,C[pc]=1;
            x=find(1,1);
            ans-=(x-2)*(x-1)/2;
            if(i%3==0&&i/3*2>=l) ans-=(i%2==0&&i/2>=l)+(i%5==0&&i/5*2>=l);//,cerr<<"!"<<i<<endl;;
        }
        cout<<ans<<endl;
    }
}