#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=50000;
int arr[MAXN][5];
bool better(int me, int other){
    int mes=0;
    int others=0;
    for(int i=0;i<5;++i){
        if(arr[me][i]<arr[other][i]){
            ++mes;
        }
        else{
            ++others;
        }
    }
    return mes>others;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
        }
        int candidate=0;
        for(int i=1;i<n;++i){
            if(better(i,candidate)){
                candidate=i;
            }
        }
        int i;
        for(i=0;i<n;++i){
            if(i!=candidate){
                if(better(i,candidate)){
                    cout<<"-1\n";
                    break;
                }
            }
        }
        if(i>=n){
            cout<<candidate+1<<'\n';
        }
    }
}