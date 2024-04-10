#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005];
int b[1005];
bool used2[1005];
int ans;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i) {
        cin>>b[i];
        memset(used2,false,sizeof(used2));
        int kol=0;
        for (int j=i-1;j>0;--j) {
            int x=b[j];
            if (x==b[i]) break;
            if (used2[x]==false) {
                used2[x]=true;
                ans+=a[x];
            }
        }
    }
    cout<<ans;
}