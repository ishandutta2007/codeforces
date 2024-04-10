#include<bits/stdc++.h>
using namespace std;

int n,t;
string ori,dc,fra;
int rd;
int tmp;
int dp[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    cin>>ori;
    int fdpt;
    for(fdpt=0;ori[fdpt]!='.';fdpt++){
        dc+=ori[fdpt];
    }
    for(fdpt++;fdpt<n;fdpt++){
        fra+=ori[fdpt];
    }
    rd=-1;
    dp[fra.size()]=1e9+1;
    for(int i=fra.size()-1;i>=0;i--){
        dp[i]=1e9+1;
        if(fra[i]>='5'){
            dp[i]=1;
        }else{
            if(fra[i]=='4')dp[i]=dp[i+1]+1;
        }
    }
    for(int i=0;i<fra.size();i++){
        if(dp[i]<=t){
            rd=i;
            break;
        }
    }
    tmp=1;
    for(int i=rd-1;i>=0;i--){
        fra[i]+=tmp;
        if(fra[i]>'9'){
            tmp=1;
            fra[i]='0';
        }else{
            tmp=0;
        }
    }
    if(rd==0){
        for(int i=dc.size()-1;i>=0;i--){
            dc[i]+=tmp;
            if(dc[i]>'9'){
                tmp=1;
                dc[i]='0';
            }else{
                tmp=0;
            }
        }
        if(tmp){
            dc='1'+dc;
        }
    }
    
    if(rd!=-1)fra.erase(rd,fra.size()-rd);
    while(fra[fra.size()-1]=='0')fra.erase(fra.size()-1,1);
    cout<<dc;
    if(fra.size()>0)cout<<'.'<<fra<<endl;

    return 0;
}