#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100001];
long long s,n;
bool cmp(pair<int,int> a, pair<int,int> b){
    return (a.first<b.first);
}
int main(){
    cin>>s>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i){
        if (a[i].first>=s) {
            cout<<"NO";
            return 0;
        } else s+=a[i].second;
    }
    cout<<"YES";
}