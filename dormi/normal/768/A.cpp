#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[(int)1e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int mi=arr[0],ma=arr[n-1];
    int am=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mi&&arr[i]<ma)am++;
    }
    printf("%d\n",am);
    return 0;
}