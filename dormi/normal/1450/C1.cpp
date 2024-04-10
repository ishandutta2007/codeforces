#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=301;
string arr[MN];
int am[2][3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int tot=0;
        for(int i=0;i<2;i++)for(int j=0;j<3;j++)am[i][j]=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            for(int j=0;j<n;j++){
                if(arr[i][j]!='.')am[arr[i][j]=='X'][(i+j)%3]++,tot++;
            }
        }
        bool done=false;
        for(int a=0;a<3&&!done;a++)for(int b=0;b<3&&!done;b++){
            if(a!=b&&am[0][a]+am[1][b]<=tot/3){
                done=true;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(arr[i][j]=='O'&&(i+j)%3==a)arr[i][j]='X';
                        else if(arr[i][j]=='X'&&(i+j)%3==b)arr[i][j]='O';
                        printf("%c",arr[i][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}