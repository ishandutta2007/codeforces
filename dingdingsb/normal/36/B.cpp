#include <bits/stdc++.h>
using namespace std;
char c[305][305],ans[305][305];
int n,m;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>c[i][j];
    int s=pow(n,m);
    for(int i=0;i<s;++i){
        for(int j=0;j<s;++j){
            int x=i;
            int y=j;
            int cnt=0;
            for(int k=0;k<m;++k){
                if (c[x%n][y%n]=='*')
                {
                    cnt=1;
                    break;
                }
                x/=n;
                y/=n;
            }
            cout<<((cnt)?'*':'.');
        }
        cout<<endl;
    }
}