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
    set<int> a;
    int b;
    for(int i=0;i<n;i++){
        cin>>b;
        a.insert(b);
    }
    for(int x:a){
        if(a.count(x+1)&&a.count(x+2)){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}