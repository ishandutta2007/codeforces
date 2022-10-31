#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int n;
int a[maxn];
int x,y;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=0;i<n-1;i++){
        int delta = abs(a[i]-a[i+1]);
        if (delta==0){
            cout<<"NO"<<endl;
            return 0;
        }
        if (delta==1)continue;
        else{
            if (y==0){
                y = delta;
            }else{
                if (delta!=y){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    if (x==0)x=1e9;
    if (y==0)y=1e9;
    for (int i=0;i<n-1;i++){
        int delta = a[i+1]-a[i];
        if (delta==1&&a[i]%y==0){
            cout<<"NO"<<endl;
            return 0;
        }
        if (delta==-1&&a[i]%y==1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    cout<<x<<" "<<y<<endl;
    return 0;
}