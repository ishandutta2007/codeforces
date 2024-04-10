#include<bits/stdc++.h>
using namespace std;
const int maxn=1555555;
const int E=maxn/2;
int _,cnt[2][maxn],n,now;
char s[maxn];
string ans;
int main(){
    cin >> _;
    while (_--){
        scanf("%s",s);
        n=strlen(s);
        for (int i=E-n-1;i<=E+n+1;i++) cnt[0][i]=cnt[1][i]=0;
        int now=E;
        for (int i=0;i<n;i++){
            if (s[i]=='0') {
                cnt[0][now]++;
                now--;
            } else {
                cnt[1][now]++;
                now++;
            }
        }
        ans="";
        int res=E;
        for (int i=0;i<n;i++){
            if (cnt[0][res]>0&&(cnt[1][res-1]>0||cnt[1][res]==0)){
                ans+="0";
                cnt[0][res]--;
                res--;
            } else {
                ans+="1";
                cnt[1][res]--;
                res++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}