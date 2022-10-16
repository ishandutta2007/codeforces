#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,a[100005],mx,num;
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),num+=a[i],mx=max(mx,a[i]);
    if (mx>num-mx||num%2==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}