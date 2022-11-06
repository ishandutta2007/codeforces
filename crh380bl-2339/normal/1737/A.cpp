#include<bits/stdc++.h>
using namespace std;
int a[30];
char s[300];
void work(){
    int n,k,i,j,l,lft;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    memset(a,0,sizeof(a));
    for(i=1;i<=n;++i){
        ++a[s[i]-'a'];
    }
    for(i=1;i<=k;++i){
        for(j=0;j<26&&j<n/k;++j){
            if(a[j]==0)break;
        }
        putchar(j+'a');
        for(l=0;l<j;++l)--a[l];
        lft=n/k-j;
       // printf("<%d>\n",j);
        for(l=j+1;l<26;++l){
            while(lft && a[l]>0){
                --lft;
                --a[l];
            }
        }
        while(lft){
            int mx=0,mid=-1;
            for(l=0;l<26;++l){
                if(a[l]>=mx){
                    mx=a[l];
                    mid=l;
                }
            }
            --lft;
            --a[mid];
        }
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}