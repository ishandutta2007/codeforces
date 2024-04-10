#include<bits/stdc++.h>
using namespace std;

int pre[1000005];
char s[1000005];

int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1),cur=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]-(s[i]=='+')+(s[i]=='-');
            if(pre[i]>cur){
                cur=pre[i];
                ans+=i;
            }
        }
        cout<<ans+n<<endl;
    }

    return 0;
}