#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int t,a,b,n,c[4],ll,o;char s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%s",&a,&b,s+1);
        n=strlen(s+1);c[1]=c[2]=c[3]=0;
        for(int i=1,j;i<=n;i++){
            j=i;
            while(j<n&&s[j+1]==s[j])j++;
            if(s[i]=='.'){
                int len=j-i+1;
                if(len>=b&&len<a)c[1]++;
                if(len>=a&&len<2*b)c[2]++;
                if(len>=2*b)c[3]++,ll=len;
            }
            i=j;
        }
        if(c[1]||c[3]>1)o=0;
        else if(!c[3])o=c[2]&1;
        else if(c[2]&1)o=ll>=2*a&&ll<=a+3*b-2;
        else o=ll<=a+2*b-2||(ll>=3*a&&ll<=a+4*b-2);
        puts(o?"YES":"NO");
    }
    return 0;
}