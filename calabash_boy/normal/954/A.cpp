#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char s[maxn];
int main(){
int n;
cin>>n;
    cin>>s;
    int ans =0;
    for (int i=0;i<n;){
        if (i==n-1){
            ans++;
            i++;
        }else{
            if (s[i]!=s[i+1]){
                ans++;
                i+=2;
            }else{
            ans++;
                i++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}