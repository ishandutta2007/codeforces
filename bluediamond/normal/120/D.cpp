#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=51;
int n,m,v[N][N],r[N],c[N];
int s[N];
int a[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    cin>>n>>m;
    ll sum=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>v[i][j];
            r[i]+=v[i][j];
            c[j]+=v[i][j];
            sum+=v[i][j];
        }
    }
    cin>>a[1]>>a[2]>>a[3];
    if(a[1]+a[2]+a[3]!=sum) {
        cout<<"0\n";
        return 0;
    }
    sort(a+1,a+4);
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+r[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=i+2;j<=n;j++) {
            int x[4];
            x[1]=s[i];
            x[2]=s[n]-s[j-1];
            x[3]=s[n]-x[1]-x[2];
            sort(x+1,x+4);
            if(a[1]==x[1] && a[2]==x[2] && a[3]==x[3]) {
                ans++;
            }
        }
    }
    for(int i=1;i<=m;i++) {
        s[i]=s[i-1]+c[i];
    }
    for(int i=1;i<=m;i++) {
        for(int j=i+2;j<=m;j++) {
            int x[4];
            x[1]=s[i];
            x[2]=s[m]-s[j-1];
            x[3]=s[m]-x[1]-x[2];
            sort(x+1,x+4);
            if(a[1]==x[1] && a[2]==x[2] && a[3]==x[3]) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**

tai de la

tai [i,i+1]

**/