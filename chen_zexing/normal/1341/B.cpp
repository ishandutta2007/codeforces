#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[200005],f[200005],pre[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        f[1]=f[n]=0;
        for(int i=2;i<n;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]) f[i]=1;
            else f[i]=0;
        }
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+f[i];
        int ans=-1,p=-1;
        for(int i=k;i<=n;i++){
            if(ans<pre[i-1]-pre[i-k+1]){
                p=i-k+1;
                ans=pre[i-1]-pre[i-k+1];
            }
        }
        cout<<ans+1<<" "<<p<<endl;
    }
    return 0;
}