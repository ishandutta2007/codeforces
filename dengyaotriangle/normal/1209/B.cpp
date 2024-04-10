#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=105;

int a[maxn],b[maxn];
bool o[maxn];
int n;
int main(){
    cin>>n;
    char _[maxn];cin>>(_+1);
    for(int i=1;i<=n;i++)o[i]=_[i]-'0';
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    int ans=0;
    for(int i=0;i<=10000;i++){
        for(int j=1;j<=n;j++){
            if(i-b[j]>=0&&(i-b[j])%a[j]==0)o[j]^=1;
        }
        int cur=0;
        for(int j=1;j<=n;j++)cur+=o[j];
        ans=max(ans,cur);
    }    
    cout<<ans;
    return 0;
}