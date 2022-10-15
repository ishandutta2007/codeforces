#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2*400;

int n;
int v[N+5][N+5];
int sl[N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    n+=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            cin>>v[i][j];
    int jum=n/2;
    for(int p=1;p<=jum;p++) {
        /// alegem max
        int ma,p1,p2;
        ma=p1=p2=0;
        for(int i=1;i<=n;i++)
            if(sl[i]==0)
                for(int j=1;j<i;j++)
                    if(sl[j]==0 && v[i][j]>ma) {
                        ma=v[i][j];
                        p1=i;
                        p2=j;
                    }
        sl[p1]=p2;
        sl[p2]=p1;
    }
    for(int i=1;i<=n;i++) {
        cout<<sl[i]<<" ";
    }
    cout<<"\n";
    return 0;
}