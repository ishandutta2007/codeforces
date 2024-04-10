#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
bool a[MAXN],b[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char in;
        for(int i=0;i<n;i++){
            cin>>in;
            a[i]=(in=='1');
        }
        for(int i=0;i<n;i++){
            cin>>in;
            b[i]=(in=='1');
        }
        vector<int> moves;
        for(int i=n-1;i>=0;i--){
            if(a[i]!=b[i]){
                if(a[0]!=a[i]){
                    moves.push_back(1);
                    a[0]=!a[0];
                }
                moves.push_back(i+1);
                reverse(a,a+i+1);
                for(int j=0;j<=i;j++)a[j]=!a[j];
            }
        }
        printf("%d ",sz(moves));
        for(auto x:moves)printf("%d ",x);
        printf("\n");
    }
    return 0;
}