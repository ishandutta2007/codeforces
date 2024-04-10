#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int prime[1000006];
vector<int> v;
void seive(){
    for(int i=2;i<1000005;i++)prime[i]=1;
    for(int i=2;i*i<=1000000;i++){
        if(prime[i]){
            for(int j=i*2;j<=1000000;j+=i){
                prime[j]=0;
            }
            v.pb(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,t;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>t;
        a[i]=t+500000;
    }
    seive();
    cout<<(n+1)<<"\n";
    cout<<"1 "<<n<<" 500000\n";
    t=3;
    int p,q,r;
    a[1]%=2;
    cout<<"2 1 1\n";
    for(int i=2;i<=n;i++){
        p=a[i]-i;
        if(prime[p])t=p;
        else{
            for(int j=i+1;;j++){
                if(p%j==0){
                    t=j;break;
                }
            }
        }
        cout<<"2 "<<i<<" "<<t<<"\n";
    }
}