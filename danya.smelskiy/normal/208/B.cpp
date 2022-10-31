#include <bits/stdc++.h>
using namespace std;


map<string,int> num;
int all;
string to[1000];
int n;
int a[10005];
bool dp[53][53][53][53];
char q1[100],q2[100];

inline bool conn(int x,int y){
    string s1=to[x];
    string s2=to[y];
    return (s1[0]==s2[0] || s1[1]==s2[1]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=8;++i)
        q1[i]=char(i+'1');
    q1[9]='T'; q1[10]='J'; q1[11]='Q'; q1[12]='K'; q1[13]='A';
    q2[1]='S'; q2[2]='D'; q2[3]='H'; q2[4]='C';
    for (int i=1;i<=4;++i) {
        for (int j=1;j<=13;++j) {
            string s="";
            s+=q1[j];
            s+=q2[i];
            ++all;
            num[s]=all;
            to[all]=s;
        }
    }
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int x=num[s];
        a[i]=x;
    }
    if (n==1) {
        cout<<"YES";
        return 0;
    }
    if (n==2 && conn(a[1],a[2])) {
        cout<<"YES";
        return 0;
    } else if (n==2) {
        cout<<"NO";
        return 0;
    }
    if (n==3) {
        if ((conn(a[3],a[2]) && conn(a[3],a[1]))) {
            cout<<"YES";
        } else cout<<"NO";
        return 0;
    }
    dp[n][a[n-2]][a[n-1]][a[n]]=true;
    for (int i=n;i>=4;--i) {
            for (int j1=1;j1<=all;++j1)
                for (int j2=1;j2<=all;++j2)
        for (int j3=1;j3<=all;++j3)  if (dp[i][j1][j2][j3]){
            if (conn(j3,j2)) dp[i-1][a[i-3]][j1][j3]=true;
            if (conn(j3,a[i-3])) dp[i-1][j3][j1][j2]=true;
        }
    }
        for (int i2=1;i2<=all;++i2)
            for (int i3=1;i3<=all;++i3)
    for (int i4=1;i4<=all;++i4) if (dp[3][i2][i3][i4]){
        if (conn(i4,i3) && conn(i4,i2)) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}