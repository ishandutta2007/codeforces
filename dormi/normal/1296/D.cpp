#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<lli,int> secret;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    lli a,b,k;
    cin>>n>>a>>b>>k;
    lli h;
    int am=0;
    for(int i=0;i<n;i++){
        cin>>h;
        lli left=h%(a+b);
        if(left==0)left+=(a+b);
        if(left<=a)am++;
        else{
            secret[(left+a-1)/a-1]++;
        }
    }
    for(auto x:secret){
        lli re=min((lli)x.second,k/x.first);
        k-=re*x.first;
        am+=re;
    }
    printf("%d\n",am);
    return 0;
}