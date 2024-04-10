#include <bits/stdc++.h>
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
        lli a,b;
        cin>>a>>b;
        if(a==b)printf("0\n");
        else if(a<b){
            if(a%2==b%2)printf("2\n");
            else printf("1\n");
        }
        else{
            if(a%2==b%2)printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}