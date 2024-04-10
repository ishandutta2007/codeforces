#include <bits/stdc++.h>
using namespace std;

int n;
string ss;
multiset<int> s;
bool sorted[300001];
int sz;
int q[300001];
int x;
int ans;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n+n;++i) {
        string ss;
        cin>>ss;
        if (ss=="add") {
            cin>>x;
            s.insert(x);
            ++sz;
            q[sz]=x;
            sorted[sz]=false;
            continue;
        } else {
            int x=q[sz];
            int y=*s.begin();
            if (sorted[sz]==true) {
                --sz;
                sorted[sz]=true;
                s.erase(s.begin());
                continue;
            }
            if (x!=y) {
                --sz;
                sorted[sz]=true;
                s.erase(s.begin());
                ++ans;
                continue;
            } else {
                s.erase(s.begin());
                --sz;
            }
        }
    }
    cout<<ans;
}