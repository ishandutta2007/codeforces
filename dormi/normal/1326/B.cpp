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
    int a;
    int ma=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>=0){
            printf("%d ",a+ma);
            ma+=a;
        }
        else{
            printf("%d ",ma+a);
        }
    }
    return 0;
}