#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x,trig=1;
        cin>>n>>x;
        int arr[2*n];
        for(int i=0;i<2*n;i++)cin>>arr[i];
        sort(arr,arr+2*n);
        for(int i=0;i<n;i++){
            if((arr[i+n]-arr[i])<x){trig=0;break;}
        }
        if(trig)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}