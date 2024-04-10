#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=500;
bool endable1(int score1, int score2, int i){
    for(;i<10;++i){
        if(i&1)++score2;
    }
    return score1>score2;
}
bool endable2(int score1, int score2, int i){
    for(;i<10;++i){
        if((i&1)==0)++score1;
    }
    return score2>score1;
}
int32_t main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin>>tc;
    for(int ct=0;ct<tc;++ct){
        string str;
        cin>>str;
        int best=10;
        {
            int score1=0,score2=0;
            for(int i=0;i<10;++i){
                int val=str[i]=='0'?0:(str[i]=='1'?1:(i&1?0:1));
                if(i&1)score2+=val;
                else score1+=val;
                if(endable1(score1,score2,i+1)){
                    best=min(best,i+1);
                    break;
                }
            }
        }
        {
            int score1=0,score2=0;
            for(int i=0;i<10;++i){
                int val=str[i]=='0'?0:(str[i]=='1'?1:(i&1?1:0));
                if(i&1)score2+=val;
                else score1+=val;
                if(endable2(score1,score2,i+1)){
                    best=min(best,i+1);
                    break;
                }
            }
        }
        cout<<best<<'\n';
    }
}