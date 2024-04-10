#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n%2 == 0){
            int mn1 = a[0],mn2 = a[1],idx1=0,idx2=1;
            for(int i=0;i<n;i+=2){
                if(mn1 > a[i]){
                    mn1 = a[i];
                    idx1 = i;
                }
                if(mn2 > a[i+1]){
                    mn2 = a[i+1];
                    idx2 = i+1;
                }
            }
            if(mn1 > mn2){
                cout<<"Mike"<<endl;
            }else if(mn1 == mn2){
                if(idx1 < idx2){
                    cout<<"Joe"<<endl;
                }else{
                    cout<<"Mike"<<endl;
                }
            }else{
                cout<<"Joe"<<endl;
            }
        }else{
            cout<<"Mike"<<endl;
        }
        }
return 0;
}