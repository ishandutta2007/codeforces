#include<bits/stdc++.h>
using namespace std;

int n,q;
int a[105];
int sum;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        cout<<(sum+n-1)/n<<endl;
    }

    return 0;
}