#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vc<int> x,y;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k,a,b;
        cin>>k>>a>>b;
        if(k==1){x.pb(a);y.pb(b);}
        else{
            a--;b--;
            int p,q,r,s,t=x.size();
            r=x[b];s=y[b];
            for(int z=0;z<t;z++){
                for(int i=0;i<t;i++){
                    p=x[i];q=y[i];
                    if((r<p&&s>p)||(r<q&&s>q)){
                        if(i==a){
                            cout<<"YES\n";
                            goto next;
                        }
                        r=min(r,p);
                        s=max(s,q);
                    }
                }
            }
            cout<<"NO\n";
        }
        next:;
    }
}