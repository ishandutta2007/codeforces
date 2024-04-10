#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn];
bool ans[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int cl=-1,cr=200005;
    for(int i=1;i<=n;i++){
        if(a[i]<=cl&&a[i]>=cr){
            cout<<"NO";
            return 0;
        }
        if(a[i]<=cl){
            cr=a[i];
            ans[i]=1;
        }else if(a[i]>=cr){
            cl=a[i];
        }else{
            if(a[i+1]>a[i]){
                cl=a[i];
            }else{
                cr=a[i];
                ans[i]=1;
            }
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}//