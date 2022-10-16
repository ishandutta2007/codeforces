//  228

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mmm memset(mem,-1,sizeof mem);
int di[8]={1,-1,0,0,1,1,-1,-1};
int dj[8]={0,0,1,-1,1,-1,1,-1};
const int N=3e5+5,MOD=998244353;
const double PI=3.141592653589793238;
ll i,n,a,ans,tmp,num;
int main(){
    //freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //mmm
    cin>>n;
    cin>>tmp;num=1;
    for(i=2;i<=n;i++){
        cin>>a;
        if(a==tmp) num++;
        else{
            tmp=a;
            ans+=num*(num+1)/2;
            num=1;
        }
    }
    ans+=num*(num+1)/2;
    cout<<ans;
    return 0;
}