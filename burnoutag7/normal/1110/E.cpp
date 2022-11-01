#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,c[200005],t[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=n-1;i>0;i--)c[i]-=c[i-1];
    for(int i=n-1;i>0;i--)t[i]-=t[i-1];
    sort(c+1,c+n);
    sort(t+1,t+n);
    cout<<(memcmp(c,t,n<<2)?"No":"Yes");

    return 0;
}