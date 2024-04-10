#include <bits/stdc++.h>
using namespace std;
long long n,ans,now,kol,x;
string s;
bool used[1000001],used2[1000001];
pair<int,int> a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s>>x;
        if (s=="+") {
            a[i].first=1;
            a[i].second=x;
            used[x]=true;
        } else {
            if (used[x]==false) {
                used2[x]=true;
                ++kol;
            } else {
                used[x]=false;
                a[i].first=-1;
                a[i].second=x;
            }
        }
    }
    now=kol;
    ans=now;
    for (int i=1;i<=n;++i){
        if (a[i].first==1){
            used2[a[i].second]=true;
            ++now;
        } else {
            used2[a[i].second]=false;
            --now;
        }
        ans=max(ans,now);
    }
    cout<<ans;
}