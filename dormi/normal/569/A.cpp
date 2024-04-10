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
    int t,s,q;
    cin>>t>>s>>q;
    int am=0;
    while(s<t){
        am++;
        s+=(q-1)*(s);
    }
    printf("%d\n",am);
    return 0;
}