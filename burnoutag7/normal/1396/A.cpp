#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){
        cout<<"1 1\n114514\n1 1\n-114514\n1 1\n"<<-a[1]<<'\n';
        return 0;
    }
    cout<<"1 "<<n<<'\n';
    for(int i=1;i<n;i++)cout<<(long long)-a[i]*n<<' ';
    cout<<"0\n";
    cout<<"1 "<<n-1<<'\n';
    for(int i=1;i<n;i++)cout<<(long long)a[i]*(n-1)<<' ';
    cout<<'\n';
    cout<<n<<' '<<n<<'\n';
    cout<<-a[n]<<'\n';

    return 0;
}