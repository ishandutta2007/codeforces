#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int n;
ll res,tmp,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    n--;
    cin>>res;
    while(n--){
        cin>>tmp;
        res=gcd(res,tmp);
    }
    cerr<<res<<endl;
    ans=1;
    for(int i=2;i<=1000000;i++){
        int cnt=0;
        while(res&&res%i==0){
            cnt++;
            res/=i;
        }
        ans*=cnt+1;
    }
    if(res!=1){
        ans*=2;
    }
    cout<<ans<<endl;

    return 0;
}