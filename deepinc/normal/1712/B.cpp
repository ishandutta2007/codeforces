#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    int t; cin>>t; while(t--){
        scanf("%d",&n);
        if(n&1){
            printf("1 ");
            for(int i=2;i<=n;++i) printf("%d ",i^1);
        }else{
            for(int i=0;i<n;++i) printf("%d ",(i^1)+1); 
        }
        puts("");
    }
}