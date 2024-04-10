#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
int a[1505][35];
map<ll,int> mp;
ll ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string s;
        ll cur=0;
        cin>>s;
        for(int j=1;j<=k;j++){
            if(s[j-1]=='S')a[i][j]=0;
            if(s[j-1]=='E')a[i][j]=1;
            if(s[j-1]=='T')a[i][j]=2;
            cur=cur*3+a[i][j];
        }
        mp[cur]++;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ll cur=0;
            for(int l=1;l<=k;l++){
                if(a[i][l]==0&&a[j][l]==0)cur=cur*3+0;
                if(a[i][l]==0&&a[j][l]==1)cur=cur*3+2;
                if(a[i][l]==0&&a[j][l]==2)cur=cur*3+1;

                if(a[i][l]==1&&a[j][l]==0)cur=cur*3+2;
                if(a[i][l]==1&&a[j][l]==1)cur=cur*3+1;
                if(a[i][l]==1&&a[j][l]==2)cur=cur*3+0;

                if(a[i][l]==2&&a[j][l]==0)cur=cur*3+1;
                if(a[i][l]==2&&a[j][l]==1)cur=cur*3+0;
                if(a[i][l]==2&&a[j][l]==2)cur=cur*3+2;
            }
            ans+=mp[cur];
        }
    }
    cout<<ans/3<<endl;

    return 0;
}