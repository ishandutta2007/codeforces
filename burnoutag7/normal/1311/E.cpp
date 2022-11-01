#include<bits/stdc++.h>
using namespace std;

int n,D,tot;
int f[5005];
int d[5005];
int s[5005];
bool u[5005];

void mian(){
    cin>>n>>D;
    {
        int cd=0,cnt=0;
        for(int i=2;i<=n;i++){
            if(__builtin_popcount(i)==1)cd++;
            cnt+=cd;
        }
        if(cnt>D||n*(n-1)/2<D){
            cout<<"NO\n";
            return;
        }else{
            cout<<"YES\n";
        }
    }
    tot=0;
    for(int i=1;i<=n;i++){
        f[i]=i-1;
        d[i]=i-1;
        tot+=d[i];
        s[i]=i!=n;
        u[i]=0;
    }
    while(tot>D){
        int x=0;
        for(int i=1;i<=n;i++){
            if(!(u[i]||s[i])&&(!x||d[x]>d[i]))x=i;
        }
        int p=0;
        for(int i=1;i<=n;i++){
            if(s[i]<2&&d[x]==d[i]+2){p=i;break;}
        }
        if(!p){
            u[x]=1;
            continue;
        }
        s[f[x]]--;
        s[p]++;
        f[x]=p;
        d[x]--;
        tot--;
    }
    for(int i=2;i<=n;i++)cout<<f[i]<<(i!=n?' ':'\n');
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}