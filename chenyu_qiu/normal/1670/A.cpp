#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
int i=0,j=0;
while (i < n) {
                if (arr[i] < 0) {
                    arr[j] *= -1;
                    j++;
                    arr[i] *= -1;
                }
                i++;
            }
            if (is_sorted(arr,arr+n)) {
               cout<<"YES"<<endl;
            } 
            else   cout<<"NO"<<endl;
}
return 0;
}