#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int n,t,i,s,s1,s2;
    cin>>t;
    while(t--){
        cin>>n;
        s=0;
        for(i=1;i<=n;++i){
            scanf("%d",&a[i]);
            s+=(a[i]==a[i-1]);
        }
        if(s<=1)puts("0");
        else{
            for(i=1;i<=n;++i){
                if(a[i]==a[i+1]){
                    s1=i+1;
                    break;
                }
            }
            for(i=n;i>=1;--i){
                if(a[i]==a[i-1]){
                    s2=i;
                    break;
                }
            }
            printf("%d\n",max(1,s2-s1-1));
        }
    }
    return 0;
}