#include<iostream>
#include<cmath>
#include<math.h>
#include<vector> 
#include<string>
#include <algorithm>
#define ed "\n"
#define int long long int
using namespace std;
 
signed main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string str;
        cin>>str;
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=str[i]-48;
        }
 
        int x=0;
        for(int i=0;i<n;i=i+2){
            int a = arr[i]+arr[i+1] ;
            if(a==1){
                x++;
            }
        }
        cout<<x<<ed;
    }
}