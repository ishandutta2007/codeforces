#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,h,p=1,cur=1;
ll f(ll p,ll cnt){
        if(cnt<p)
                return cnt;
        else
                return cnt+1;
}
ll gt(ll p,ll cur){
        if(p%2==1)
                return f(p,cur);
        else
                if(cur==k-1)
                        return f(p,1);
                else
                        return f(p,cur+1);
}
int main(){
        cin>>n>>k;
        h=k*(k-1);
        if(n>h)
                cout<<"NO\n";
        else{
                cout<<"YES\n";
                for(int i=1;i<=n;i++){
                        cout<<p<<" "<<gt(p,cur)<<"\n";
                        p++;
                        if(p>k){
                                p=1;
                                cur++;
                        }
                }
        }
}