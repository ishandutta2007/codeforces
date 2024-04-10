#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int cnt[10];
string ch="codeforces";
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll k;
    cin>>k;
    ll am=1;
    for(int i=0;i<10;i++)cnt[i]++;
    int i=0;
    while(am<k){
        am=am/cnt[i]*(cnt[i]+1);
        cnt[i]++;
        i=(i+1)%10;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<cnt[i];j++)printf("%c",ch[i]);
    }
    return 0;
}