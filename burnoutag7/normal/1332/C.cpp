#include<bits/stdc++.h>
using namespace std;

int n,k;
char s[200005];
int f[200005];
int cnt[200005][26];

int find(int x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    f[x]=y;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cin>>s+1;
        iota(f+1,f+1+n,1);
        for(int st=1;st<=k;st++){
            for(int i=st;i+k<=n;i+=k){
                unite(i,i+k);
            }
        }
        for(int i=1;i<=n;i++)unite(i,n+1-i);
        for(int i=1;i<=n;i++)memset(cnt[find(i)],0,sizeof(cnt[0]));
        for(int i=1;i<=n;i++){
            cnt[find(i)][s[i]-'a']++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(f[i]==i){
                ans-=*max_element(cnt[i],cnt[i]+26);
                for(int j=0;j<26;j++)ans+=cnt[i][j];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}