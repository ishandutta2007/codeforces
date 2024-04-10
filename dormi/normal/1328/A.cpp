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
    int n;
    cin>>n;
    lli a,b;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        printf("%lli\n",(b-(a%b))%b);
    }
    return 0;
}