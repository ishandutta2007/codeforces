#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=2005;
const string id[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n,k;
string st[maxn];
bool dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>st[i];
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=9;j++){
            int dl=0;
            for(int k=0;k<7;k++){
                if(st[i][k]=='0'&&id[j][k]=='1')dl++;
                if(st[i][k]=='1'&&id[j][k]=='0'){dl=-1;break;}
            }
            if(dl!=-1){
                for(int p=dl;p<=k;p++)dp[i][p]|=dp[i+1][p-dl];
            }
        }
    }
    if(!dp[1][k]){cout<<-1;return 0;}
    int cp=k;
    for(int i=1;i<=n;i++){
        for(int j=9;j>=0;j--){
            int dl=0;
            for(int k=0;k<7;k++){
                if(st[i][k]=='0'&&id[j][k]=='1')dl++;
                if(st[i][k]=='1'&&id[j][k]=='0'){dl=-1;break;}
            }
            if(dl!=-1&&cp>=dl&&dp[i+1][cp-dl]==1){
                cout<<j;
                cp-=dl;
                break;
            }
        }
    }
    return 0;
}