#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int l,r,cur;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    l=0,r=n-1;
    while(l<=r){
        if(a[l]<=cur&&a[r]<=cur)break;
        if(a[l]>cur&&a[r]<=cur){
            cur=a[l];
            l++;
            s+='L';
        }
        if(a[l]<=cur&&a[r]>cur){
            cur=a[r];
            r--;
            s+='R';
        }
        if(a[l]>cur&&a[r]>cur){
            if(a[l]==a[r]){
                int cntl=0,cntr=0;
                for(int i=l+1;i<=r;i++){
                    if(a[i]>a[i-1])cntl++;
                    else break;
                }
                for(int i=r-1;i>=l;i--){
                    if(a[i]>a[i+1])cntr++;
                    else break;
                }
                if(cntl>cntr){
                    for(int i=l;i<=r&&a[i]>cur;i++){
                        cur=a[i];
                        s+='L';
                    }
                }else{
                    for(int i=r;i>=l&&a[i]>cur;i--){
                        cur=a[i];
                        s+='R';
                    }
                }
                cout<<s.size()<<endl<<s<<endl;
                return 0;
            }
            if(a[l]<a[r]){
                cur=a[l];
                l++;
                s+='L';
            }else{
                cur=a[r];
                r--;
                s+='R';
            }
        }
    }
    cout<<s.size()<<endl<<s<<endl;

    return 0;
}