#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
int arr[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i][i];
    }
    for(int i=1;i<n;i++){
        int loc=0;
        for(int j=0;j<n-(i-1);j++){
            if(arr[i-1+j][j]==i)loc=j;
        }
        for(int j=0;j<n-(i-1);j++){
            if(loc==j)continue;
            if(j<loc){
                arr[i+j][j]=arr[i-1+j][j];
            }
            else{
                arr[i-1+j][j-1]=arr[i-1+j][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}