#include<bits/stdc++.h>
using namespace std;

int n,a[100005];
queue<int> s,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n==1){
        cin>>a[1];
        cout<<"0\n"<<a[1]<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[1])swap(a[i],a[1]);
    }
    for(int i=2;i<=n;i++){
        if(a[i]>a[n])swap(a[i],a[n]);
    }
    swap(a[1],a[n]);
    sort(a+2,a+n);
    for(int i=2;i<n;i++){
        if(s.size()<n-1>>1)s.push(a[i]);
        else b.push(a[i]);
    }
    for(int i=2;i<n;i++){
        if(i&1){
            a[i]=b.front();
            b.pop();
        }else{
            a[i]=s.front();
            s.pop();
        }
    }
    int cnt=0;
    for(int i=2;i<n;i++){
        cnt+=a[i]<a[i-1]&&a[i]<a[i+1];
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<endl;

    return 0;
}