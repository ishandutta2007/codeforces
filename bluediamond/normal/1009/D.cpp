#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b) {
    if(b==0)
        return a;
    return gcd(b,a%b);
}

const int N=100000;
int n,m,a[N+5],b[N+5],cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m<n-1) {
        cout<<"Impossible\n";
        return 0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(gcd(i,j)==1) {
                cnt++;
                a[cnt]=i;
                b[cnt]=j;
                if(cnt==m) {
                    cout<<"Possible\n";
                    for(int i=1;i<=m;i++) {
                        cout<<a[i]<<" "<<b[i]<<"\n";
                    }
                    return 0;
                }
            }
        }
    }
    cout<<"Impossible\n";
    return  0;
}