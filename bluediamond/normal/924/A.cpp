#include <bits/stdc++.h>

using namespace std;

const int N=50;

int n,m;
string a;
int v[N+5][N+5];
int p[N+5],y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        string a;
        cin>>a;
        y=0;
        for(int j=0;j<m;j++)
            if(a[j]=='#')
                p[++y]=j+1;
        for(int j=1;j<=y;j++) {
            int val=p[j];
            if(v[val][0]==0) {
                v[val][0]=y;
                for(int k=1;k<=y;k++)
                    v[val][k]=p[k];
                continue;
            }
            bool ok=1;
            if(v[val][0]!=y)
                ok=0;
            for(int k=1;k<=y;k++)
                if(v[val][k]!=p[k])
                    ok=0;
            if(ok==0) {
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}
/**

5 8
.#.#..#.
.....#..
.#.#..#.
#.#....#
.....#..

........
........
........
........
........

**/