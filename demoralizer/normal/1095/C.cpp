#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
ll p[31];int q[31];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll w=1;
    for(int i=0;i<31;i++){
        p[i]=w;w*=2;
    }
    int n,k;
    cin>>n>>k;
    int m=n;
    int c=0;int i=0;
    while(m!=0){
        if(m%2==1)c++;
        q[i]=m%2;i++;
        m/=2;
    }
    if(k<c||k>n){
        cout<<"NO";return 0;
    }
    cout<<"YES\n";
    while(c<k){
        for(int i=1;i<31;i++){
            if(q[i]>=1){
                q[i]--;q[i-1]+=2;c++;break;
            }
        }
    }
    for(int i=0;i<31;i++){
        for(int j=0;j<q[i];j++){
            cout<<p[i]<<" ";
        }
    }
}