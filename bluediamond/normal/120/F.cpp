#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=101;
int t,n;
vector<int>v[N];
int d[N];
int ans=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            v[i].clear();
        }
        for(int i=1;i<n;i++) {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ma=0;
        for(int i=1;i<=n;i++) {
            queue<int>q;
            for(int j=1;j<=n;j++)d[j]=-1;
            d[i]=0;
            q.push(i);
            while(!q.empty()) {
                int nod=q.front();
                q.pop();
                ma=max(ma,d[nod]);
                for(auto nou:v[nod]) {
                    if(d[nou]==-1) {
                        d[nou]=d[nod]+1;
                        q.push(nou);
                    }
                }
            }
        }
        ans+=ma;
    }
    cout<<ans<<"\n";
    return 0;
}
/**
s
**/