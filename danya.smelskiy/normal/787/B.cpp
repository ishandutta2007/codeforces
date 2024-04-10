#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long x;
long long a[10005];
map<long long,int> last;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>k;
        for (int j=1;j<=k;++j){
            cin>>a[j];
            x=a[j];
            last[x]=i;
        }
        bool t=false;
        for (int j=1;j<=k;++j){
            x=a[j];
            if (x<0 && last[abs(x)]==i) {
                t=true;
                break;
            }
            else if (x>0 && last[-x]==i) {
                t=true;
                break;
            }
        }
        if (t==false) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}