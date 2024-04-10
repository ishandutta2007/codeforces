#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[(int)2e5+2];
int inc[(int)2e5+2];
int de[(int)2e5+2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    arr[n+1]=1e9+1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]>arr[i-1])inc[i]=inc[i-1]+1;
        else inc[i]=1;
        ans=max(ans,inc[i]);
    }
    for(int i=n;i>=1;i--){
        if(arr[i]<arr[i+1])de[i]=de[i+1]+1;
        else de[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(arr[i-1]<arr[i+1])ans=max(ans,inc[i-1]+de[i+1]);
    }
    printf("%d\n",ans);
    return 0;
}