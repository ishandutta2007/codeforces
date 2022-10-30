#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn],n;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n/2;i++){
        scanf("%d",a+i);
    }
    sort(a,a+n/2);
    int ans = 1000000;
    int tempAns =0;
    for (int i=0;i<n/2;i++){
        tempAns+=abs(a[i]-2*i-1);
    }
    ans = min(ans,tempAns);
    tempAns=0;
    for (int i=0;i<n/2;i++){
        tempAns+=abs(a[i]-2*i-2);
    }
    ans = min(ans,tempAns);
    cout<<ans<<endl;
    return 0;
}