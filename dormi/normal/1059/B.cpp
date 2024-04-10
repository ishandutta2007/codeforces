#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[1001][1001];
pii moves[4]={{1,1},{-1,-1},{1,-1},{-1,1}};
int n,m;
int checkhsh(int i, int j){
    if(i<0||i>=n||j<0||j>=m)return false;
    if(arr[i][j]=='#')return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    bool work=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='#'){
                bool te=false;
                for(int k=0;k<4;k++){
                    if(checkhsh(i, j + moves[k].second) && checkhsh(i, j + 2 * moves[k].second) && checkhsh(i + moves[k].first, j) &&
                       checkhsh(i + 2 * moves[k].first, j) &&
                       checkhsh(i + moves[k].first * 2, j + moves[k].second) &&
                       checkhsh(i + moves[k].first, j + 2 * moves[k].second) &&
                       checkhsh(i + moves[k].first * 2, j + 2 * moves[k].second)){
                        te=true;
                    }
                }
                for(int k=-1;k<=1;k+=2){
                    if(checkhsh(i,j+2*k)&&checkhsh(i+1,j)&&checkhsh(i-1,j)&&checkhsh(i+1,j+k)&&checkhsh(i+1,j+2*k)&&checkhsh(i-1,j+k)&&checkhsh(i-1,j+2*k)){
                        te=true;
                    }
                    if(checkhsh(i+2*k,j)&&checkhsh(i,j+1)&&checkhsh(i,j-1)&&checkhsh(i+k,j+1)&&checkhsh(i+2*k,j+1)&&checkhsh(i+k,j-1)&&checkhsh(i+2*k,j-1)){
                        te=true;
                    }
                }
                if(!te)work=false;
            }
        }
    }
    if(work)printf("YES\n");
    else printf("NO\n");
    return 0;
}