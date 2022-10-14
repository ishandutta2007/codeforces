#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int onecnt=0,zerocnt=0;
        for(char x:s){
            if(x=='0')zerocnt++;
            else onecnt++;
        }
        int a=min(zerocnt,onecnt);
        if(a%2)printf("DA\n");
        else printf("NET\n");
    }
    return 0;
}