#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int q,n,len;char s[N],c[N];
bitset<N>b[30],ans;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1;i<=n;i++)b[s[i]-'a'][i]=1;
    scanf("%d",&q);
    for(int i=1,op,l,r;i<=q;i++){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%s",&l,c);
            b[s[l]-'a'][l]=0;
            s[l]=c[0];
            b[s[l]-'a'][l]=1;
        }
        else{
            scanf("%d%d%s",&l,&r,c+1);
            len=strlen(c+1);
            if(r-l+1<len){puts("0");continue;}
            int t=r-len+1;ans.set();
            for(int j=1;j<=len;j++)ans&=b[c[j]-'a']>>(j-1);
            printf("%d\n",(ans>>l).count()-(ans>>(t+1)).count());
        }
    }
    return 0;
}