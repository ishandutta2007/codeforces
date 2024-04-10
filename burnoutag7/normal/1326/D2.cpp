#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[1000005],ans[1000005];
char t[2000005];
int z[2000005],tl;

int Z(){
    int len=tl*2,l=1,r=1;
    z[1]=len;
    for(int i=2;i<=len;i++){
        z[i]=0;
        if(i>r){
            l=i;r=i-1;
            while(r<len&&t[r+1]==t[z[i]+1])r++,z[i]++;
        }else{
            if(i+z[i-l+1]<=r){
                z[i]=z[i-l+1];
            }else{
                l=i;
                z[i]=r-i+1;
                while(r<len&&t[r+1]==t[z[i]+1])r++,z[i]++;
            }
        }
        if(i>len/2&&i+z[i]>len){return z[i];}
    }
    return 0;
}

int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int len=strlen(s+1);
        int l=1,r=len;
        while(s[l]==s[r]&&l<r){
            l++;
            r--;
        }
        tl=r-l+1;
        for(int i=l;i<=r;i++){
            t[i-l+1]=t[(r-l+1)*2-(i-l)]=s[i];
        }
        int lenl=min(Z(),r-l+1);//cerr<<t+1<<endl;
        for(int i=l;i<=r;i++){
            t[i-l+1]=t[(r-l+1)*2-(i-l)]=s[r-(i-l)];
        }
        int lenr=min(Z(),r-l+1);//cerr<<t+1<<endl;cerr<<lenl<<' '<<lenr<<endl;
        int al,ar;
        if(lenl>=lenr){
            al=l;ar=l+lenl-1;
        }else{
            al=r-lenr+1;ar=r;
        }
        memcpy(ans,s+1,l-1);
        memcpy(ans+l-1,s+al,ar-al+1);
        memcpy(ans+l-1+ar-al+1,s+r+1,l-1);
        ans[(l-1)*2+(ar-al+1)]='\0';
        printf("%s\n",ans);
    }

    return 0;
}