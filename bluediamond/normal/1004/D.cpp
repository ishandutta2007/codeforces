#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int T=1000000;
int t,ap[T+5];
int cnt[T+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++) {
        int x;
        cin>>x;
        ap[x]++;
    }
    int ma=0;
    for(int i=0;i<=t;i++)
        if(ap[i])
            ma=i;
    int x=-1;
    for(int i=1;i<=t;i++)
        if(ap[i]!=4*i) {
            x=i;
            break;
        }
    if(x==-1 || ap[0]!=1) {
        cout<<"-1\n";
        return 0;
    }
    for(int n=1;n<=t;n++) {
        if(t%n==0) {
            int m=t/n;
            int y=n+m-ma-x;
            if(1<=x && x<=n && 1<=y && y<=m) {
                for(int r=1;r<=n;r++)
                    for(int c=1;c<=m;c++) {
                        cnt[abs(r-x)+abs(c-y)]++;
                    }
                bool ok=1;
                for(int j=0;j<=t;j++) {
                    if(cnt[j]!=ap[j]) {
                        ok=0;
                    }
                    cnt[j]=0;
                }
                if(ok) {
                    cout<<n<<" "<<m<<"\n";
                    cout<<x<<" "<<y<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"-1\n";
    return 0;
}
/**

**/