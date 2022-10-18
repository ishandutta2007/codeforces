#include<bits/stdc++.h>

using namespace std;

const int maxn=505;

int n;

int main(){
    cin>>n;
    long long ans=0;
    for(int i=2;i<n;i++){
        ans+=i*(i+1);
    }
    cout<<ans;
    return 0;
}