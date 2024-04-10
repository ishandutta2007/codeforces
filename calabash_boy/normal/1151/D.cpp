#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
typedef long long ll;
vector<int > pos,neg;
int main(){
    int n;
    ll ans = 0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ans += 1ll * b * n - a;
        a -= b;
        if (a > 0)pos.push_back(a);
        else if (a < 0)neg.push_back(a);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    reverse(pos.begin(),pos.end());
    int idx = n;
    for (int a : neg){
        ans += 1ll * a * idx;
        idx --;
    }
    idx = 1;
    for (int a : pos){
        ans += 1ll * a * idx;
        idx ++;
    }
    cout<<ans<<endl;
    return 0;
}