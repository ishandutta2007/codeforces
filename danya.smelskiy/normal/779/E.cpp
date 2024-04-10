#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int q1[5001][1001];
int q2[5001][1001];
int last;
int pol1[5001];
int pol2[5001];
bool tt[5001];
int ans[5001];
string nam;
int typ[5001];
map<string,int> pos;
int t1[5001],t2[5001];
inline int chek(int x,int y){
    int qqw=0;
    for (int i=1;i<=n;++i){
        if (tt[i]){
            int z1,z2;
            if (t1[i]==0) z1=y;
            else if (t1[i]==1) z1=q1[i][x];
            else z1=ans[pol1[i]];
            if (t2[i]==0) z2=y;
            else if (t2[i]==1) z2=q2[i][x];
            else z2=ans[pol2[i]];
            if (typ[i]==0) ans[i]=(z1&z2);
            else if (typ[i]==1) ans[i]=(z1^z2);
            else ans[i]=(z1|z2);
            qqw+=ans[i];
        } else {
            if (t1[i]==0) ans[i]=y;
            else if (t1[i]==1) ans[i]=q1[i][x];
            else ans[i]=ans[pol1[i]];
            qqw+=ans[i];
        }
    }
    return qqw;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    getline(cin,s);
    for (int i=1;i<=n;++i){
        getline(cin,s);
        nam="";
        for (int j=0;s[j]!=' ';++j){
            last=j;
            nam+=s[j];
        }
        pos[nam]=i;
        last+=5;
        if (s[last]=='?') {
            t1[i]=0;
            ++last;
        } else if (s[last]>='0' && s[last]<='9'){
            t1[i]=1;
            int kol=0;
            for (;s[last]>='0' && s[last]<='9';++last){
                ++kol;
                if (s[last]=='1')
                q1[i][kol]=1;
                else q1[i][kol]=0;
            }
        } else {
            t1[i]=2;
            string qq="";
            for (;s[last]!=' ';++last){
                qq+=s[last];
            }
            pol1[i]=pos[qq];
        }
        if (last==s.size() ) {
            tt[i]=false;
            continue;
        }
        tt[i]=true;
        ++last;
        string qwer="";
        for (;s[last]!=' ';++last){
            qwer+=s[last];
        }
        if (qwer=="XOR") typ[i]=1;
        else if (qwer=="AND") typ[i]=0;
        else typ[i]=2;
        ++last;
        if (s[last]=='?') {
            t2[i]=0;
        } else if (s[last]>='0' && s[last]<='9') {
            t2[i]=1;
            int kol2=0;
            for (;last<s.size();++last){
                ++kol2;
                if (s[last]=='1')
                q2[i][kol2]=1;
                else q2[i][kol2]=0;
            }
        } else {
            t2[i]=2;
            string qq2="";
            for (;last<s.size();++last){
                qq2+=s[last];
            }
            pol2[i]=pos[qq2];
        }
    }
    string ans1="",ans2="";
    for (int i=1;i<=m;++i){
        int zxc1=0,zxc2=0;
        for (int j=0;j<=1;++j){
            if (j==0) zxc1=chek(i,j);
            else zxc2=chek(i,j);
        }
        if (zxc1>zxc2) {
            ans1+="0";
            ans2+="1";
        } else if (zxc1==zxc2){
            ans1+="0";
            ans2+="0";
        } else {
            ans1+="1";
            ans2+="0";
        }
    }
    cout<<ans2<<'\n'<<ans1;
}