#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
char s[10000];
int cnt[10000];
void output(vector<int> ans){
    for (int ch : ans){
        for (int i=0;i<cnt[ch];i++){
            printf("%c",ch);
        }
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    for (int o=0;o<T;o++){
        scanf("%s",s);
        int n = strlen(s);
        for (int i='a';i<='z';i++){
            cnt[i] = 0;
        }
        for (int i=0;i<n;i++){
            cnt[s[i]] ++;
        }
        vector<int> chs(0);
        for (int i='a';i<='z';i++){
            if (cnt[i])chs.push_back(i);
        }
        vector<int> ans(0);
        if (chs.size() >= 4 || chs.size() == 1){
            for (int i=1;i<chs.size();i+=2){
                ans.push_back(chs[i]);
            }
            for (int i=0;i<chs.size();i+=2){
                ans.push_back(chs[i]);
            }
        }else if (chs.size() == 2) {
            if (abs(chs[0] - chs[1]) == 1){
                puts("No answer");
                continue;
            }else{
                ans = chs;
            }
        }else if (chs.size() == 3){
            if (chs[2] - chs[1] == 1 && chs[1] - chs[0] == 1){
                puts("No answer");
                continue;
            }
            if (chs[2] - chs[1] == 1){
                ans.push_back(chs[2]);
                ans.push_back(chs[0]);
                ans.push_back(chs[1]);
            }else if (chs[1] - chs[0] == 1){
                ans.push_back(chs[1]);
                ans.push_back(chs[2]);
                ans.push_back(chs[0]);
            }else{
                ans = chs;
            }
        }else assert(0);
        output(ans);
    }
}