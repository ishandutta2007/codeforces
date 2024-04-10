#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
double d[100005];
int a[100005];
ll sum;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        a[i]=floor(d[i]);
        sum+=a[i];
    }
    for(int i=1;sum<0;i++){
        if(a[i]==d[i])continue;
        a[i]++;
        sum++;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}