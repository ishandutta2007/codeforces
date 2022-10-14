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
    int q;
    cin>>q;
    while(q--){
        lli a,b,c;
        cin>>a>>b>>c;
        lli mi=LLONG_MAX;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                for(int k=-1;k<=1;k++){
                    mi=min(mi,abs(a+i-b-j)+abs(a+i-c-k)+abs(c+k-b-j));
                }
            }
        }
        printf("%lli\n",mi);
    }
    return 0;
}