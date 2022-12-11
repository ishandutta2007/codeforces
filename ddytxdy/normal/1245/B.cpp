#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,a,b,c,a1,b1,c1,aa,bb,cc;char s[N],ans[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);a1=b1=c1=0;aa=a;bb=b;cc=c;
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            if(s[i]=='P'){
                c1++;
                if(c)ans[i]='S',c--;
            }
            if(s[i]=='S'){
                a1++;
                if(a)ans[i]='R',a--;
            }
            if(s[i]=='R'){
                b1++;
                if(b)ans[i]='P',b--;
            } 
        }
        if(min(a1,aa)+min(b1,bb)+min(c1,cc)>=(n+1)/2){
            puts("YES");
            for(int i=1;i<=n;i++){
                if(ans[i])putchar(ans[i]);
                else if(a)putchar('R'),a--;
                else if(b)putchar('P'),b--;
                else putchar('S'),c--;
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}