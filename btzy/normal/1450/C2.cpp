#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=300;
char arr[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        int k[3];
        k[0]=k[1]=k[2]=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>arr[i][j];
                if(arr[i][j]=='X')++k[(i+j)%3];
                if(arr[i][j]=='O')++k[(i+j+1)%3];
            }
        }
        int idx=static_cast<int>(min_element(k,k+3)-k);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if((i+j)%3==idx&&arr[i][j]=='X'){
                    cout<<'O';
                }
                else if((i+j+1)%3==idx&&arr[i][j]=='O'){
                    cout<<'X';
                }
                else{
                    cout<<arr[i][j];
                }
            }
            cout<<'\n';
        }
    }
}