#include <bits/stdc++.h>
using namespace std;




int n,m;
long long ans2,ans1;
long long a[1001];
string b[1001];
map<string,int> kol;
inline bool cmp(string a,string b){
    if (kol[a]==kol[b]) return a<b;
    else return kol[a]>kol[b];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=m;++i) {
        cin>>b[i];
        ++kol[b[i]];
    }
    sort(b+1,b+m+1,cmp);
    int kol1=1;
    for (int i=1;i<=m;++i) {
        if (i==1 || (i>1 && b[i]!=b[i-1])) {
            if (i>1) ++kol1;
            ans1+=kol[b[i]]*a[kol1];
        }
    }
    kol1=1;
    for (int i=1;i<=m;++i) {
        if (i==1 || (i>1 && b[i]!=b[i-1])){
            if (i>1) kol1++;
            ans2+=kol[b[i]]*a[n-kol1+1];
        }
    }
    cout<<ans1<<" "<<ans2;
}