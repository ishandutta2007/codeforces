#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
lli psa[MAXN];
lli am[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;
        int in;
        for(int i=0;i<26;i++)am[i]=0;
        psa[1]+=1;
        for(int i=0;i<m;i++){
            psa[1]+=1;
            cin>>in;
            psa[in+1]-=1;
        }
        for(int i=1;i<=n;i++){
            psa[i]+=psa[i-1];
            psa[i-1]=0;
            am[a[i-1]-'a']+=psa[i];
        }
        psa[n]=0;
        for(int i=0;i<26;i++)printf("%lli ",am[i]);
        printf("\n");
    }
    return 0;
}