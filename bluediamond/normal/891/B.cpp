#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=22+5;
int n,v[N],ans[N];
pair<int,int>a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        a[i]={v[i],i};
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        ans[a[i].second]=a[(i+1)%n].first;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
/**


**/