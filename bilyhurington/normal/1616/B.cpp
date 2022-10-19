#include<bits/stdc++.h>
using namespace std;
int T,n;char s[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %s",&n,s+1);
        int ans=n;
        for(int i=1;i<n;i++){
            if(s[i+1]>s[i]){
                // printf("%d\n",i);
                ans=i;break;
            }
        }string S1;
        for(int i=1;i<=ans;i++) S1+=s[i];
        for(int i=ans;i>=1;i--) S1+=s[i];
        string S2;S2+=s[1];S2+=s[1];
        cout<<min(S1,S2)<<endl;
    }
    return 0;
}
//4+x=2+2x x=2