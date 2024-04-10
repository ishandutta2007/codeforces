#include<bits/stdc++.h>
using namespace std;
const int N=110;
int T,n;char s[N],t[N];
string S="abacaba";
void solve(){
    scanf("%d%s",&n,s+1);bool flag=0;
    for(int i=1;i+7-1<=n;i++){
        memcpy(t,s,sizeof(s));
        bool fl=1;
        for(int j=0;j<7;j++){
            if(s[i+j]!=S[j])
                if(s[i+j]!='?'){fl=0;break;}
                else t[i+j]=S[j];
        }
        if(!fl)continue;
        for(int j=1;j<i;j++)if(t[j]=='?')t[j]='z';
        for(int j=i+7;j<=n;j++)if(t[j]=='?')t[j]='z';
        int num=0;
        for(int j=1;j+7-1<=n;j++){
            bool fl=1;
            for(int k=0;k<7;k++)
                if(t[j+k]!=S[k]){fl=0;break;}
            num+=fl;
        }
        if(num==1){
            puts("YES");flag=1;
            for(int j=1;j<=n;j++)putchar(t[j]);
            puts("");
            break;
        }
    }
    if(!flag)puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}