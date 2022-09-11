#include<iostream>
using namespace std;
long long a[1000000];
main(){
    int n,i,j;
    long long an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i+=j){
        for(j=1;i+j<n&&a[i+j]==a[i];j++);
        an+=(long long)j*(j+1)/2;
    }
    cout<<an<<endl;
}