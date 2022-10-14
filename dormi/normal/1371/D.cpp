#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
bool done[301];
bool table[301][301];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            if(i<k%n)done[i]=false;
            else done[i]=true;
        }
        if(k%n)printf("2\n");
        else printf("0\n");
        int ree=k/n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<i+ree&&j>=i)table[i][j]=true;
                else if((i+ree)%n>j&&i+ree>n)table[i][j]=true;
                else table[i][j]=false;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!done[j]&&!table[i][j]){
                    table[i][j]=true,done[j]=true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(table[i][j])printf("1");
                else printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}