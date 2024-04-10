#include<bits/stdc++.h>
using namespace std;
const int N=600;
int T,l,r,p,n;char s[N],a[N];bool inq[130];
void solve(){
    scanf("%s",s+1);n=strlen(s+1);
    memset(inq,0,sizeof(inq));
    l=r=300;p=l;inq[s[1]]=1;
    for(int i=p-n;i<=p+n;i++)a[i]=0;
    a[p]=s[1];
    for(int i=2;i<=n;i++){
        if(s[i]==a[p-1])p--;
        else if(s[i]==a[p+1])p++;
        else if(!inq[s[i]]&&p==l)a[--p]=s[i],l--,inq[s[i]]=1;
        else if(!inq[s[i]]&&p==r)a[++p]=s[i],r++,inq[s[i]]=1;
        else{puts("NO");return;}
    }
    puts("YES");
    for(int i=l;i<=r;i++)putchar(a[i]);
    for(int i=0;i<26;i++)if(!inq[i+'a'])putchar(i+'a');
    puts("");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}