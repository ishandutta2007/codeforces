#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e3+1;
int arr[MAXN];
int tot[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        tot[0]=0,tot[1]=0;
        int last=0;
        int l=0,r=n-1;
        int turn=0;
        int games=0;
        while(l<=r){
            games++;
            if(turn==0){
                int am=0;
                while(l<=r&&am<=last){
                    am+=arr[l];
                    l++;
                }
                last=am;
                tot[turn]+=am;
            }
            else{
                int am=0;
                while(l<=r&&am<=last){
                    am+=arr[r];
                    r--;
                }
                last=am;
                tot[turn]+=am;
            }
            turn=!turn;
        }
        printf("%d %d %d\n",games,tot[0],tot[1]);
    }
    return 0;
}