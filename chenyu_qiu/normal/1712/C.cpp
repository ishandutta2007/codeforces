#include<bits/stdc++.h>
using namespace std;
 
 
 
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int j=-1;
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1]){
                j=i;
                break;
            }
        }
        map<int,int> m;
        for(int i=0;i<=j;i++){
            if(m[a[i]]==0){
                m[a[i]]++;
            }
 
        }
        int mx=j;
        for(int i=j+1;i<n;i++){
            if(m[a[i]]==1){
                mx=max(mx,i);
 
            }
        }
        // cout<<mx<<" "<<j<<"hie"<<endl;
        m.clear();
        for(int i=0;i<=mx;i++){
            if(m[a[i]]==0){
                m[a[i]]++;
            }
        }
        cout<<m.size()<<endl;
    }
 
return 0;
}