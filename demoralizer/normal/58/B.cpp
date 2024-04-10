#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<n<<" ";
    for(int i=2;i<=n;i++){
        while(n%i==0){
            n/=i;
            cout<<n<<" ";
        }
    }
}