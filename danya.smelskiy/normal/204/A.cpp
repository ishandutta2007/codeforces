#include <bits/stdc++.h>
using namespace std;


long long dp[30][30][30][10];
string s,ss;
long long x,y;
inline string get(long long x){
    if (x==0) return "0";
    string res="";
    while (x) {
        res=res+char(x%10+'0');
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

inline long long f(string s){
    if (s=="0") return 0;
    for (int i=1;i<=s.size();++i){
        for (int f=0;f<=9;++f)
            for (int l=0;l<=9;++l){
                for (int k=0;k<=1;++k)
                    dp[i][f][l][k]=0;
            }
    }
    for (int i=1;i<s[0]-'0';++i)
        dp[1][i][i][0]=1;
    dp[1][s[0]-'0'][s[0]-'0'][1]=1;
    for (int i=1;i<s.size();++i){
        for (int f=0;f<=9;++f){
            for (int l=0;l<=9;++l){
                for (int k=0;k<=1;++k){
                    for (int z=0;z<=9;++z){
                        if (k==0) {
                            dp[i+1][f][z][k]+=dp[i][f][l][k];
                        } else {
                            if (z>(s[i]-'0')) break;
                            if (z==(s[i]-'0')) {
                                dp[i+1][f][z][k]+=dp[i][f][l][k];
                            } else {
                                dp[i+1][f][z][0]+=dp[i][f][l][k];
                            }
                        }
                    }
                }
            }
        }
    }
    long long res=0;
    for (int i=0;i<=9;++i)
            for (int k=0;k<=1;++k){
                res+=dp[s.size()][i][i][k];
            //    if (dp[s.size()][i][j][k])
              //  cout<<i<<" "<<j<<" "<<k<<" "<<dp[s.size()][i][j][k]<<endl;
            }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    x--;
    s=get(x);
    ss=get(y);
    long long ans=0;
    string last="";
    for (int i=1;i<ss.size();++i){
        last+="9";
        ans+=f(last);
    }
    ans+=f(ss);
    last="";
    for (int i=1;i<s.size();++i){
        last+="9";
        ans-=f(last);
    }
    ans-=f(s);
    cout<<ans;
}