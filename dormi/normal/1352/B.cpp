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
        int n,k;
        cin>>n>>k;
        if(k%2==0&&n%2==1){
            printf("NO\n");
            continue;
        }
        if(k%2==0){
            if(k<=n){
                printf("YES\n");
                printf("%d ",n-(k-1));
                for(int i=1;i<k;i++){
                    printf("1 ");
                }
                printf("\n");
            }
            else{
                printf("NO\n");
                continue;
            }
        }
        else{
            if(n%2==0){
                if(2*k<=n){
                    printf("YES\n");
                    printf("%d ",n-(2*(k-1)));
                    for(int i=1;i<k;i++){
                        printf("2 ");
                    }
                    printf("\n");
                }
                else{
                    printf("NO\n");
                    continue;
                }
            }
            else{
                if(k<=n){
                    printf("YES\n");
                    printf("%d ",n-(k-1));
                    for(int i=1;i<k;i++){
                        printf("1 ");
                    }
                    printf("\n");
                }
                else{
                    printf("NO\n");
                    continue;
                }
            }
        }
    }
    return 0;
}