#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli x,y,a,b;
        cin>>x>>y>>a>>b;
        lli lo=0;
        lli hi=1e9;
        while(lo!=hi){
            lli mid=(lo+hi)/2+1;
            if(x+a*mid<=y-b*mid)lo=mid;
            else hi=mid-1;
        }
        if(x+a*lo==y-b*lo){
            printf("%lli\n",lo);
        }
        else printf("-1\n");
    }
    return 0;
}