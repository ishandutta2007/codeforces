#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1916333,e7=1e7+7,inf=1e17;typedef ll aN[N];ll cnt=1;char s1[N],s2[N],s3[N],s4[N],t[28];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}ll fffl=0;
void reads(char*s,int l='0',int r='z'){*s=readchar(l,r);while(*++s=getchar(),*s>=l&&*s<=r);*s=0;}ll vis[288],l[1145141];
void calc(ll cases){
    ll n=readll();reads(s1+1,'a','z'),reads(s2+1,'a','z'),reads(s3+1,'a','z');ll len=strlen(s1+1);
    memset(t,0,sizeof t),memset(vis,0,sizeof vis);strcpy(s4+1,s1+1);
    ll flag=0,lst=0;
    #define qmin(st) rep(c,st,n)if(!vis[c]){vis[t[s1[i]]=c]=1;break;}
    rep(i,1,len)s1[i]-=96,s2[i]-=96,s3[i]-=96;
//    rep(i,1,len)printf("%d",s1[i]);puts("");
//    rep(i,1,len)printf("%d",s2[i]);puts("");
//    rep(i,1,len)printf("%d",s3[i]);puts("");
    rep(i,1,len)//{
    
    if(flag){if(!t[s1[i]]){qmin(1);}}
    else{
        l[i]=lst;
        if(t[s1[i]]){
            if(t[s1[i]]<s2[i])
                do{i=l[i],vis[t[s1[i]]]=0,t[s1[i]]=0,flag=1;qmin(s2[i]+1);}while(!t[s1[i]]&&i);
            if(t[s1[i]]>s2[i])flag=1;
        }else{
            qmin(s2[i]);lst=i;while(!t[s1[i]]&&i){
            i=l[i],vis[t[s1[i]]]=0,t[s1[i]]=0,flag=1;qmin(s2[i]+1);}
            if(t[s1[i]]>s2[i])flag=1;
        }
    }//;
//    printf("%lld %lld:",i,l[i]);rep(i,1,n+1)printf("%d ",t[i]);puts("");printf("v=%lld\n",flag);}
    rep(i,1,n)if(!t[i]){rep(c,1,n)if(!vis[c]){vis[t[i]=c]=1;break;}}(void)cases;
//    rep(i,1,n+1)printf("%d ",t[i]);puts("");//puts(t+1);
//    if(fffl){ll f=0;rep(i,1,n)if(t[i]>n||t[i]<0||vis[t[i]]<0)vis[t[i]]--,f=1;
//    if(f){printf("%lld\n",n),puts(s4+1),puts(s2+1),puts(s3+1);}}
    rep(i,1,len)s1[i]=t[s1[i]];rep(i,1,len)s1[i]+=96,s2[i]+=96,s3[i]+=96;rep(i,1,n)t[i]+=96;
    if(!fffl){if(strcmp(s1+1,s2+1)>=0&&strcmp(s1+1,s3+1)<=0)puts("YES"),puts(t+1);else puts("NO");}
}
int main(){/*IO(1085E);*/ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}
/*
1
4
abaaaa
cddbda
dabbda
*/
/*
1
5
bcdbccc
adbedae
eecdaca
5
dbeedcbcbaccdddbdcbcabacecbe
dcaeaabaadacddcdecbbebcbadcb
ddbacaaabdaeedaacbabebccebbd
*/
/*
1
4
abbaa
cddda
dccdd
*/
/*
1
1
aaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaa
*/
/*
1
4
caadcaabda
cddcabccab
dbcbcaaada
4
daacdaabca
cddcabccab
dbcbcaaada
*/