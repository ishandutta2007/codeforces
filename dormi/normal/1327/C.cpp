#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    printf("%d\n",n-1+m-1+m-1+(n-1)*(m-1)+n-1);
    for(int i=0;i<n-1;i++){
        printf("U");
    }
    for(int i=0;i<m-1;i++){
        printf("L");
    }
    for(int i=0;i<m-1;i++)printf("R");
    for(int i=0;i<n-1;i++){
        printf("D");
        if(i%2)for(int j=0;j<m-1;j++)printf("R");
        else for(int j=0;j<m-1;j++)printf("L");
    }

    return 0;
}