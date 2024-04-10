#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=3e5+50;
const double eps=1e-12;
int n,a[N],lim,pre[N];string s;bool fl[N];
vector<int>v;
bool ask(int x){
    printf("? ");
    v.clear();
    for(int i=1;i<=n;i++)
        if(i>>x&1)v.pb(i);
    printf("%d ",v.size());
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    puts("");
    cout.flush();
    cin>>s;
    return s=="YES";
}
bool out(){
    int ans=0;
    for(int i=0;i<lim;i++)
        ans|=a[i]<<i;
    printf("! %d\n",ans);
    cout.flush();
    cin>>s;
    if(s==":)")exit(0);
    return 0;
}
void solve(){
    out();
    for(int i=0;i<lim;i++)
        if(!fl[i])a[i]^=1;
    out();
}
int main(){
    scanf("%d",&n);
    while((1<<lim)<=n)lim++;
    a[0]=ask(0)^1;
    pre[0]=-1;
    pre[1]=0;
    for(int i=1;i<lim;i++){
        a[i]=ask(i);
        int p=i;
        while(1){
            int x=ask(p);
            if(a[p]!=x){pre[i+1]=p;break;}
            if(p!=i)x=ask(p);
            if(a[p]==x)fl[p]=1,p=pre[p];
            else{pre[i+1]=p;break;}
            if(p==-1)break;
        }
        if(p==-1)pre[i+1]=-1;
    }
    int p=pre[lim];
    if(p==-1)out(),exit(0);
    for(int i=0;i<lim;i++)
        if(!fl[i]){
            int x=ask(i);
            if(x==a[i])solve();
            else{
                a[i]=x,fl[i]=1;
                int p=pre[lim];
                if(p==x)solve();
                while(1){
                    x=ask(p);
                    if(x!=a[p]){pre[lim]=p;break;}
                    x=ask(p);
                    if(x!=a[p]){pre[lim]=p;break;}
                    else fl[p]=1,p=pre[p];
                    if(p==x)break;
                }
                if(p==x)solve();
            }
        }
    solve();
    return 0;
}