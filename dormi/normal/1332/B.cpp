#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int primes[11]={2,3,5,7,11,13,17,19,23,29,31};
int ans[1001];
int cor[11];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a;
        int cur=1;
        for(int i=0;i<11;i++)cor[i]=0;
        for(int i=0;i<n;i++) {
            cin >> a;
            for(int j=0;j<11;j++){
                if(a%primes[j]==0){
                    if(cor[j]==0)cor[j]=cur++;
                    ans[i]=cor[j];
                    break;
                }
            }
        }
        printf("%d\n",cur-1);
        for(int i=0;i<n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}