#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


int m;
int d;
int dp2[3][3005][15][3];
inline long long  f(string s){
    for (int i=2;i<=s.size();i+=2)
        if (s[i-1]!=char(d+'0')) return 0;
    for (int i=1;i<=s.size();i+=2)
        if (s[i-1]==char(d+'0')) return 0;
    long long sum=0;
    for (int i=0;i<s.size();++i)
        sum=(sum*10+s[i]-'0')%m;
    if (sum) return 0;
    return 1;
}
inline string getto(int x){
    string res="";
    if (x==0) return "0";
    while (x) {
        res=(res+char(x%10+'0'));
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
inline int get_from(string s){
    int res=0;
    for (int i=0;i<s.size();++i)
        res=res*10+s[i]-'0';
    return res;
}

long long solve(string s){
    if (s.size()==1) {
        int x=s[0]-'0';
        int res=0;
        for (int i=0;i<=x;++i)
            if (i!=d && i%m==0)
            ++res;
        return res;
    }
    long long res=0;
  int n=s.size();
    for (int i=0;i<2;++i)
        for (int j=0;j<m;++j)
            for (int k=0;k<=9;++k)
                for (int z=0;z<2;++z)
                    dp2[i][j][k][z]=0;
    int xx=s[0]-'0';
    for (int i=1;i<xx;++i)
        if (i!=d) dp2[0][i%m][i][0]=1;
    if (xx!=d) dp2[0][xx%m][xx][1]=1;
    int x2=0,y2=1;
    for (int i=1;i<n;++i) {
        swap(x2,y2);
        for (int j=0;j<m;++j)
            for (int k=0;k<=9;++k)
                for (int z=0;z<2;++z)
                dp2[x2][j][k][z]=0;
        for (int j=0;j<m;++j) {
            for (int k=0;k<2;++k){
                xx=s[i]-'0';
                if (i&1) {
                    int nxt=(j*10+d)%m;
                    for (int z=0;z<10;++z) if (dp2[y2][j][z][k]){
                        if (k==0) dp2[x2][nxt][d][0]=(dp2[x2][nxt][d][0]+dp2[y2][j][z][k])%md;
                        else {
                            if (d<xx) dp2[x2][nxt][d][0]=(dp2[x2][nxt][d][0]+dp2[y2][j][z][k])%md;
                            else if (d==xx) dp2[x2][nxt][d][1]=(dp2[x2][nxt][d][1]+dp2[y2][j][z][k])%md;
                        }
                    }
                } else if (dp2[y2][j][d][k]){
                    for (int z=0;z<10;++z) if (z!=d) {
                        int nxt=(j*10+z)%m;
                        if (k==0) dp2[x2][nxt][z][0]=(dp2[x2][nxt][z][0]+dp2[y2][j][d][0])%md;
                        else {
                            if (z<xx) dp2[x2][nxt][z][0]=(dp2[x2][nxt][z][0]+dp2[y2][j][d][k])%md;
                            else if (z==xx) dp2[x2][nxt][z][1]=(dp2[x2][nxt][z][1]+dp2[y2][j][d][k])%md;
                        }
                    }

                }
            }
        }
    }
    for (int i=0;i<=9;++i)
        for (int j=0;j<2;++j)
        res=(res+dp2[x2][0][i][j])%md;
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    string a,b;
    cin>>m>>d;
    cin>>a>>b;
    cout<<(solve(b)-solve(a)+f(a)+md+md)%md;
}