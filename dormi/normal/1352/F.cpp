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
    int t;
    cin>>t;
    while(t--){
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        if(n1%2==0&&n1>0)printf("0"),n1--;
        for(int i=0;i<=n2&&n2>0;i++){
            printf("1");
        }
        if(n1>0&&n2==0)printf("1");
        for(int i=0;i<n1;i++){
            printf("%d",i%2);
        }
        if(n1==0&&n0>0)printf("0");
        for(int i=0;i<n0;i++)printf("0");
        printf("\n");
    }
    return 0;
}