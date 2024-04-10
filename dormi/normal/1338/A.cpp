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
    while(t--) {
        int n;
        cin >> n;
        lli ma=INT_MIN;
        lli largestdiff=0;
        lli a;
        for (int i = 0; i < n; i++) {
            cin>>a;
            ma=max(ma,a);
            largestdiff=max(largestdiff,ma-a);
        }
        bool done=false;
        for(lli i=40;i>=0;i--){
            if(largestdiff&((lli)1<<i)){
                printf("%lli\n",i+1);
                done=true;
                break;
            }
        }
        if(!done)printf("0\n");
    }
    return 0;
}