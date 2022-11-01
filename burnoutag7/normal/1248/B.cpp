#include<bits/stdc++.h>
using namespace std;

int n;
long long x,y;
int a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        y+=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n/2;i++){
        x+=a[i];
    }
    y-=x;
    cout<<x*x+y*y<<endl;

    return 0;
}