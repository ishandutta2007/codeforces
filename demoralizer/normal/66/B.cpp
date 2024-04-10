#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int m=-1;
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=i-1;j>=0;j--){
            if(a[j]<=a[j+1])c++;
            else break;
        }
        for(int j=i+1;j<n;j++){
            if(a[j]<=a[j-1])c++;
            else break;
        }
        if(c>m)m=c;
    }
    cout<<(m+1);
}