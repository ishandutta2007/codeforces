#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[1010];
int n,x,y,k=-100000,p = 0,b[1010];
int main() {
    cin>>n;
    for(int i= 0;i<n;i++){
        cin>>x>>y;
        if(x>y)swap(x,y);
        a[i]=make_pair(y,x);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        if(a[i].second>k)
            k=a[i].first,
            b[p++]=a[i].first;
    }
    cout<<p<<endl;
    for(int i=0;i<p;i++)
        cout<<b[i]<<' ';
    return 0;
}