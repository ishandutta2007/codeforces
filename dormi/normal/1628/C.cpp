#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1001;
int arr[MN][MN];
bool covered[MN][MN];
int xdir[4]={1,-1,0,0};
int ydir[4]={0,0,1,-1};
pii convert(pii topleft, int len, int cur){
    if(cur<len){
        return {topleft.A,topleft.B+cur};
    }
    if(cur<2*len-1){
        return {topleft.A+cur-(len-1),topleft.B+len-1};
    }
    if(cur<3*len-2){
        return {topleft.A+len-1,topleft.B+len-1-(cur-(2*len-2))};
    }
    return {topleft.A+len-1-(cur-(3*len-3)),topleft.B};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                covered[i][j]=false;
            }
        }
        int val=0;
        auto select=[&](int a, int b){
            val^=arr[a][b];
            for(int i=0;i<4;i++){
                if(a+xdir[i]>=0&&a+xdir[i]<n&&b+ydir[i]>=0&&b+ydir[i]<n){
                    covered[a+xdir[i]][b+ydir[i]]=true;
                }
            }
        };
        for(int i=0;i<4*(n-1);i++){
            if(i%4<=1){
                pii loc=convert({0,0},n,i);
                select(loc.A,loc.B);
            }
        }
        for(int gridlevel=2;n-gridlevel*2>0;gridlevel+=2){
            int m=n-gridlevel*2;
            pii topleft={gridlevel,gridlevel};
            for(int i=0;i<m;i++){
                pii loc=convert(topleft,m,i);
                if(!covered[loc.A-1][loc.B])select(loc.A,loc.B);
            }
            for(int i=m;i<2*m-1;i++){
                pii loc=convert(topleft,m,i);
                if(!covered[loc.A][loc.B+1])select(loc.A,loc.B);
            }
            for(int i=2*m-1;i<3*m-2;i++){
                pii loc=convert(topleft,m,i);
                if(!covered[loc.A+1][loc.B])select(loc.A,loc.B);
            }
            for(int i=3*m-2;i<4*(m-1);i++){
                pii loc=convert(topleft,m,i);
                if(!covered[loc.A][loc.B-1])select(loc.A,loc.B);
            }
        }
        printf("%d\n",val);
    }
    return 0;
}