#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
bool mk[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int pi=-1,pd=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(a[i]>pi){
            if(a[i]<pd){
                if(a[i+1]<a[i]){
                    mk[i]=1;
                    pd=a[i];
                }else{
                    pi=a[i];
                }
            }else{
                pi=a[i];
            }
        }else{
            if(a[i]<pd){
                mk[i]=1;
                pd=a[i];
            }else{
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)cout<<mk[i]<<' ';

    return 0;
}