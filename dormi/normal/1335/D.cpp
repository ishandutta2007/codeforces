#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[9][9];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)cin>>arr[i][j];
        }
        for(int i=0;i<9;i++){
            int y=((i%3)*3)+i/3;
            if(arr[i][y]=='9')arr[i][y]='1';
            else arr[i][y]='9';
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)printf("%c",arr[i][j]);
            printf("\n");
        }
    }
    return 0;
}