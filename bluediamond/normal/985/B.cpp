#include <bits/stdc++.h>

using namespace std;

const int N=2000;
int n;
vector<int>v[N+5];
int ap[N+5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        for(int j=0;j<m;j++){
            v[i].push_back(a[j]-'0');
            ap[j]+=a[j]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        bool ok=1;
        for(int j=0;j<m;j++){
            if(ap[j]-v[i][j]<=0){
                ok=0;
                break;
            }
        }
        if(ok==1){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
/**




**/