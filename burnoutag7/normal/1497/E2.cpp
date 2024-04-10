#include<bits/stdc++.h>
using namespace std;

int n,k,a[200005],pre[200005][21],f[200005][21],cnt[10000005];

void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int &b=a[i];
        for(int j=2;j*j<=b;j++){
            while(b%(j*j)==0)b/=j*j;
        }
    }
    for(int kk=0;kk<=k;kk++){
        for(int ck=0,l=1,r=0;l<=n;l++){
            while(r<n&&(bool)cnt[a[r+1]]+ck<=kk){
                r++;
                ck+=(bool)cnt[a[r]];
                cnt[a[r]]++;
                pre[r][kk]=l;
            }
            cnt[a[l]]--;
            ck-=(bool)cnt[a[l]];
        }
    }
    for(int i=1;i<=n;i++)for(int j=0;j<=k;j++){
        f[i][j]=1145141919;
        for(int x=0;x<=j;x++)f[i][j]=min(f[i][j],f[pre[i][x]-1][j-x]+1);
    }
    cout<<*min_element(f[n],f[n]+k+1)<<'\n';
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