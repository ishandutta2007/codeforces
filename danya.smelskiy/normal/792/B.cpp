#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001];
bool used[100001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i)
        cin>>a[i];
    int last=1;
    for (int i=1;i<=m;++i){
        a[i]%=(n-i+1);
        if (a[i]>0){
        ++last;
        if (last>n) last=1;
        }
            while (a[i]) {
                if (used[last]==false) {
                    --a[i];
                    if (a[i]==0) break;
                    ++last;
                    if (last>n) last=1;
                } else {
                    ++last;
                    if (last>n) last=1;
                }
            }
        cout<<last<<" ";
        used[last]=true;
        while (true) {
            if (used[last]==false) break;
            ++last;
            if (last>n) last=1;
        }
    }
}