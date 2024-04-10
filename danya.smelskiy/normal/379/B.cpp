#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (a[1]) {
        cout<<"P";
        --a[1];
    }
    int it=0;
    int last=1;
    while (true) {
        ++it;
        bool t=false;
        for (int i=1;i<=n;++i) if (a[i]) {
            t=true;
            break;
        }
        if (!t) break;
        if (it&1) {
            for (int i=1;i<n;++i) {
                cout<<"R";
                ++last;
                if (a[last]) {
                    --a[last];
                    cout<<"P";
                }
            }
        } else {
            for (int i=1;i<n;++i) {
                cout<<"L";
                --last;
                if (a[last]) {
                    --a[last];
                    cout<<"P";
                }
            }
        }
    }
}