#include <bits/stdc++.h>
using namespace std;

int n;
string s[1001];
int main(){
    cin>>n;
    int ans=6;
    for (int i=1;i<=n;++i){
        cin>>s[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)   if (i!=j) {
            int q=0;
            for (int z=0;z<6;++z)
                if (s[i][z]!=s[j][z]) q++;
            ans=min(ans,(q-1)/2);
        }
    }
    cout<<ans;
}