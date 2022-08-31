#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,z=0;
    cin>>n>>m;
    char c[n][m];
    for(int i=0;i<n;i++)cin>>c[i];

    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            for(int i=1;i<=n-x;i++){
                for(int j=1;j<=m-y;j++){
                    int k=1;
                    for(int p=x;p<i+x;p++){
                        for(int q=y;q<j+y;q++){
                            if(c[p][q]=='1'){k=0;goto abc;}
                        }
                    }
                    abc:;
                    if(k)z=max(z,2*(i+j));
                }
            }
        }
    }
    cout<<z;
}