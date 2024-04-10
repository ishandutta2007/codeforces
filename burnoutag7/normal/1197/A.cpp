#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        cout<<max(min(n-2,min(a[n],a[n-1])-1),0)<<endl;
    }

    return 0;
}