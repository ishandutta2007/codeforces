#include <bits/stdc++.h>
#define SIZE(x) ((int)x.size())
using namespace std;
#define VECTOR_INT vector<int>
map<int, string> ans;
int n;
string s[3];
int jud = 0;
map<char,int> mp;
VECTOR_INT cnt(3);
void init(){
    ans[0]="Draw";
    ans[1]= "Kuro";
    ans[2]="Shiro";
    ans[3]="Katie";
    ans[4]= "Draw";
}
void input(){
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
}
void solve(){
    if(cnt[0]>cnt[1]&&cnt[0]>cnt[2])jud += 1;
    else if(cnt[1]>cnt[0]&&cnt[1]>cnt[2]) jud += 2;
    else if(cnt[2]>cnt[0]&&cnt[2]>cnt[1]) jud += 3;
}
void work(){
    for(int i=0;i<3;i++) {
        mp.clear();
        for(char c: s[i]) {
            mp[c]++;
            cnt[i]=max(cnt[i],mp[c]);
        }
        if(cnt[i]==SIZE(s[i])&&n == 1) cnt[i]--;
        else cnt[i]=min(cnt[i]+n,SIZE(s[i]));
    }
    solve();
}
void output(){
    cout<<ans[jud]<<endl;
}
int main() {
    input();
    init();
    work();
    output();
    return 0;
}