#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e2 + 10;

int m,t,r;
int main(){
    priority_queue<int> q;
    fast_io;
    int ans=0;
    cin >> m>>t>>r;
    int a[m];
    if(r>t) return cout << -1,0;
    for(int i=0; i<m; i++) cin >> a[i];
    bool mark[900];
    fill(mark,mark+900,false);
    bool *fl=mark+450;
    for(int i=0; i<m; i++){
        int cnt=0;
        for(int j=1; j<=t; j++){
            if(fl[a[i]-j]) cnt++;
        }
        if(cnt<r){
            cnt=r-cnt;
            for(int j=1; j<=t; j++){
                if(cnt==0) break;
                if(!fl[a[i]-j]) fl[a[i]-j]=true,ans++,cnt--;
            }
        }
    }
    cout << ans;
    return 0;
}