#include<iostream>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=300005;

int n;
long long a[maxn];
long long sfx[maxn];

int main(){
    ios::sync_with_stdio(0);
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        sfx[i]=sfx[i+1]+a[i];
    }
    long long ans=sfx[1];
    sort(sfx+2,sfx+1+n);
    for(int i=n;i>=2;i--){
        if(k>1){
            ans+=sfx[i];
            k--;
        }
    }
    cout<<ans;
    return 0;
}