#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=(1<<8);
const int itn=10;

int n;
string dp[itn][maxn][3];
//0:or
//1:and
//2:all

void upd(string& trg,string org){
    if(trg.empty())trg=org;
    else if(org.size()<trg.size())trg=org;
    else if(org<trg&&org.size()==trg.size())trg=org;
}

int main(){
    dp[0][0b00001111][2]='x';
    dp[0][0b00110011][2]='y';
    dp[0][0b01010101][2]='z';
    for(int i=0;i<itn-1;i++){
        for(int j=0;j<maxn;j++){
            if(!dp[i][j][0].empty())upd(dp[i+1][j][0],dp[i][j][0]);
            if(!dp[i][j][1].empty())upd(dp[i+1][j][1],dp[i][j][1]);
            if(!dp[i][j][2].empty())upd(dp[i+1][j][2],dp[i][j][2]);
            if(!dp[i][j][0].empty())upd(dp[i+1][j][2],"("+dp[i][j][0]+")");
            if(!dp[i][j][1].empty())upd(dp[i+1][j][2],"("+dp[i][j][1]+")");
            if(!dp[i][j][2].empty())upd(dp[i+1][j][2],"("+dp[i][j][2]+")");
            if(!dp[i][j][2].empty())upd(dp[i+1][0b11111111^j][2],"!"+dp[i][j][2]);
        }
        for(int j=0;j<maxn;j++){
            for(int k=0;k<maxn;k++){
                if(!dp[i][j][0].empty()&&!dp[i][k][1].empty())upd(dp[i+1][j|k][0],dp[i][j][0]+"|"+dp[i][k][1]);
                if(!dp[i][j][0].empty()&&!dp[i][k][2].empty())upd(dp[i+1][j|k][0],dp[i][j][0]+"|"+dp[i][k][2]);
                if(!dp[i][j][1].empty()&&!dp[i][k][1].empty())upd(dp[i+1][j|k][0],dp[i][j][1]+"|"+dp[i][k][1]);
                if(!dp[i][j][1].empty()&&!dp[i][k][2].empty())upd(dp[i+1][j|k][0],dp[i][j][1]+"|"+dp[i][k][2]);
                if(!dp[i][j][2].empty()&&!dp[i][k][1].empty())upd(dp[i+1][j|k][0],dp[i][j][2]+"|"+dp[i][k][1]);
                if(!dp[i][j][2].empty()&&!dp[i][k][2].empty())upd(dp[i+1][j|k][0],dp[i][j][2]+"|"+dp[i][k][2]);
                if(!dp[i][j][1].empty()&&!dp[i][k][2].empty())upd(dp[i+1][j&k][1],dp[i][j][1]+"&"+dp[i][k][2]);
                if(!dp[i][j][2].empty()&&!dp[i][k][2].empty())upd(dp[i+1][j&k][1],dp[i][j][2]+"&"+dp[i][k][2]);
            }
        }
    }
    cerr<<1;

    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        char f[10];
        cin>>f;
        int o=0;
        for(int i=0;i<8;i++) o=(o<<1|(f[i]-'0'));
        string ans="";
        upd(ans,dp[itn-1][o][0]);
        upd(ans,dp[itn-1][o][1]);
        upd(ans,dp[itn-1][o][2]);
        cout<<ans<<'\n';
    }
    return 0;
}