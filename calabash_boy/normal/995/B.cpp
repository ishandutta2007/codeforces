//
// Created by calabash_boy on 18-6-25.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
const int maxn = 105;
int a[maxn];
int n;
int ans=0;
int main(){
    cin >> n;
    for(int i=1;i<=n*2;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n*2;i+=2) {
        if(a[i+1]!=a[i]) {
            int t;
            for(int j=i+1;j<=n*2;j++)
                if(a[j]==a[i]) {
                    t=j;
                    break;
                }
            for(int j = t;j>=i+2;j--) {
                swap(a[j],a[j-1]);
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}