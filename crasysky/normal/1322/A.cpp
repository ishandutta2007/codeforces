#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e6+6;
string s;
int main(){
    int n; cin>>n;
    cin>>s; int c=0;
    for (int i=1;i<=n;++i) c+=s[i-1]=='('?1:-1;
    if (c){ cout<<-1<<endl; return 0; }
    int ans=n,mn=0,lst=0;
    for (int i=1;i<=n;++i){
        c+=s[i-1]=='('?1:-1,mn=min(mn,c);
        if (c==0){
            if (mn>=0) ans-=i-lst;
            mn=0,lst=i;
        }
    }
    cout<<ans<<endl;
}