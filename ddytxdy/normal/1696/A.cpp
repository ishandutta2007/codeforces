#include<cmath>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N=2020;
int T,n,z,a[N],mx;
void solve(){
    scanf("%d%d",&n,&z);mx=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),mx=max(mx,a[i]|z);
    cout<<mx<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
}