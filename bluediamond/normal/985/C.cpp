#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000;
int n,k,l,v[N+5];
ll sum=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>l;
    for(int i=1;i<=n*k;i++){
        cin>>v[i];
    }
    sort(v+1,v+n*k+1);
    int cate=n*k;
    while(cate>1 && v[cate]-v[1]>l)
        cate--;
    if(cate<n){
        puts("0");
        return 0;
    }
    int lft=n*k-cate;

    for(int i=cate;i>=1;i--){
        lft++;
        if(lft>=k){
            lft-=k;
            sum+=v[i];
        }
    }
    cout<<sum<<"\n";
    return 0;
}
/**




**/