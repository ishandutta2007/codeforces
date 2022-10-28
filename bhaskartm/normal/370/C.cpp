#include<iostream>
#include<algorithm>
using namespace std;
int a[5010],n,s=0,i;
int main(){
    cin>>n>>i;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)s+=a[i]!=a[(i+n/2)%n];
    cout<<s<<endl;
    for(i=0;i<n;i++)cout<<a[i]<<" "<<a[(i+n/2)%n]<<endl;
}