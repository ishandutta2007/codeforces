#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500000+5;
int n,q,p;
string a;

int st[N],dr[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q>>p;
    cin>>a;
    a="x"+a;
    for(int i=1;i<=n;i++) {
        st[i]=i-1;
        dr[i]=i+1;
    }
    dr[0]=1;
    string mov;
    cin>>mov;
    for(auto itr:mov) {
        if(itr=='L') {
            p=st[p];
            continue;
        }
        if(itr=='R') {
            p=dr[p];
            continue;
        }
        /// p == 'D'
        if(a[p]=='(') {
            int init=p;
            int vf=1;
            while(vf>0) {
                p=dr[p];
                if(a[p]=='(') {
                    vf++;
                }
                else {
                    vf--;
                }
            }
            dr[st[init]]=dr[p];
            st[dr[p]]=st[init];
            if(dr[p]<=n) {
                p=dr[p];
            }
            else {
                p=st[init];
            }
            continue;
        }
        /// a[p]==')'
        int init=p;
        int vf=-1;
        while(vf<0) {
            p=st[p];
            if(a[p]=='(') {
                vf++;
            }
            else {
                vf--;
            }
        }
        dr[st[p]]=dr[init];
        st[dr[init]]=st[p];
        if(dr[init]<=n) {
            p=dr[init];
        }
        else {
            p=st[p];
        }
    }
    int p=dr[0];
    while(p<=n) {
        cout<<a[p];
        p=dr[p];
    }
    cout<<"\n";
    return 0;
}
/**

init -> p

**/