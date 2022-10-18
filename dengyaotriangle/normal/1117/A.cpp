#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int t=*max_element(a+1,a+1+n);
    int cl=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==t){
            cl++;
            ans=max(ans,cl);
        }else{
            cl=0;
        }
    }    
    cout<<ans;
    return 0;
}