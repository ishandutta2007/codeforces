#include <cstdio>
#include <set>
using namespace std;
char s[1600], g[30];
int k, ans = 0;
set<unsigned long long int> find[1600];
int main(){
    scanf("%s%s%d", s, g, &k);
    for(int i = 0; s[i]; ++i){
        int cnt = 0, len = 0;
        unsigned long long int xd = 0;
        for(int j = i;s[j]; ++j, ++len){
            xd = xd*131 + (s[j]-('a'-1));
            if(g[s[j]-'a']=='0') ++cnt;
            if(cnt<=k){
                if(find[len].count(xd)<=0){ ++ans;find[len].insert(xd);}
            }
            else break;
        }
    }
    printf("%d\n", ans);
    return 0;
}