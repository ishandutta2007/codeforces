#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e3+1;
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,h;
    cin>>n>>h;
    int a;
    int last=h;
    lli ans=1;
    lli open=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(abs(a-last)>1){
            printf("0\n");
            return 0;
        }
        if(a==last){
            ans=ans*(open+1)%mod;
        }
        else if(a>last){
            ans=ans*open%mod;
            open-=1;
            if(open<0){
                printf("0\n");
                return 0;
            }
        }
        else{
            open+=1;
        }
        last=a;
    }
    if(open>1){
        printf("0\n");
        return 0;
    }
    printf("%lli\n",ans);
    return 0;
}