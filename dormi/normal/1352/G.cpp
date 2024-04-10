#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int pat[4]={2,4,1,3};
int baf[7]={1,4,2,6,3,5,7};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<4){
            printf("-1\n");
            continue;
        }
        if(((n%4)==2)||((n%4)==3)){
            for(int i=0;i<n-7;i+=4){
                for(int j=0;j<4;j++)printf("%d ",pat[j]+i);
            }
            for(int i=0;i<4+(n%4);i++){
                printf("%d ",baf[i]+n-(4+(n%4)));
            }
            printf("\n");
        }
        else{
            for(int i=0;i<n;i+=4){
                if(i+3<n) {
                    for (int j = 0; j < 4; j++) {
                        printf("%d ", pat[j] + i);
                    }
                }
                else{
                    printf("%d",n);
                }
            }
            printf("\n");
        }
    }
    return 0;
}