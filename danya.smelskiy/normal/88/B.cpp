#include <bits/stdc++.h>
using namespace std;
int n,m;
long double x;
string s[100];
long double q1[100];
long double q2[100];
int ans;

void chek(long double x,long double y,long double xx,long double yy,long double z){
    long double xxx=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
    int r=(s[(int)x][(int)y-1]-'a');
    if (xxx<=z) q2[r]=min(q2[r],xxx);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
    }
    for (int i=0;i<26;++i)
        q1[i]=1e9;
    for (int i=0;i<26;++i)
        q2[i]=1e9;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    if (s[i][j-1]!='S') {
        for (int ii=1;ii<=n;++ii)
        for (int jj=1;jj<=m;++jj)
            if (s[ii][jj-1]=='S') chek((long double) i,(long double ) j,(long double ) ii,(long double ) jj, x);
        q1[s[i][j-1]-'a']=0;
    }
    bool t=false;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        if (s[i][j-1]=='S') t=true;
    cin>>n;
    string ss;
    cin>>ss;
    int ans=0;
    for (int i=1;i<=n;++i) {
        char c=ss[i-1];
        if (c>='a')  {
            if (q1[c-'a']==1e9) {
                cout<<"-1";
                return 0;
            }
        } else {
            if (q2[c-'A']==1e9) {
                ++ans;
                c=c-'A';
                if (q1[c]==1e9 || t==false) {
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }
    cout<<ans;
}