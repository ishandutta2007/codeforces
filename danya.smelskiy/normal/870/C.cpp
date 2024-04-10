#include <bits/stdc++.h>
using namespace std;
int n;
int m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>m;
        if (m==1 || m==2 || m==3 || m==5 || m==7 || m==11) {
                cout<<"-1"<<'\n';
                continue;
        }
        if (m%4==0) {
            cout<<m/4<<'\n';
            continue;
        }
        if (m%4==1) {
            cout<<m/4-1<<'\n';
            continue;
        }
        if (m%4==2) {
            cout<<m/4<<'\n';
            continue;
        }
        if (m%4==3) {
            cout<<m/4-1<<'\n';
            continue;
        }
    }
}