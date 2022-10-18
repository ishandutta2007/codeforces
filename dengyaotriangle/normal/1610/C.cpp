#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;
int a[maxn],b[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        int l=0,r=n;
        while(l<r){
            int m=(l+r+1)/2;
            int cur=0;
            for(int i=1;i<=n;i++){
                if(cur<=b[i]){
                    if(m-cur-1<=a[i])cur++;
                }
            }
            if(cur>=m)l=m;
            else r=m-1;
        }
        cout<<l<<'\n';
    }
    return 0;
}