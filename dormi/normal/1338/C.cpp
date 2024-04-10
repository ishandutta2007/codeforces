#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli calc(lli begin, lli end, lli term){
    if(begin==end)return begin;
    lli am=end-begin+(lli)1;
    if(term<=am/(lli)4){
        return calc(begin,begin+am/(lli)4-(lli)1,term);
    }
    else if(term<=am/(lli)2){
        return calc(end-am/(lli)4+(lli)1,end,term-am/(lli)4);
    }
    else if(term<=am/(lli)4*(lli)3){
        return calc(begin+am/(lli)4,begin+am/(lli)2-(lli)1,term-am/(lli)2);
    }
    else{
        return calc(begin+am/(lli)2,end-am/(lli)4,term-am/(lli)4*(lli)3);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli mod=n%(lli)3;
        n=(n-1)/(lli)3+(lli)1;
        lli cur=1;
        while(n>cur){
            n-=cur;
            cur*=4;
        }
        lli first=cur+n-1;
        lli third=calc(cur*(lli)3,cur*(lli)4-(lli)1,n);
        lli second=third^first;
        if(mod==1)printf("%lli\n",first);
        else if(mod==2)printf("%lli\n",second);
        else printf("%lli\n",third);
    }
    return 0;
}