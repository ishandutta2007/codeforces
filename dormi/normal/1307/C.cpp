#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli am[26];
lli am2[26][26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string t;
    cin>>t;
    for(char x:t){
        int cur=x-'a';
        for(int i=0;i<26;i++){
            am2[i][cur]+=am[i];
        }
        am[cur]++;
    }
    lli ans=0;
    for(int i=0;i<26;i++){
        ans=max(ans,am[i]);
        for(int j=0;j<26;j++){
            ans=max(ans,am2[i][j]);
        }
    }
    printf("%lli\n",ans);
    return 0;
}