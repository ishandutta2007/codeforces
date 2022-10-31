#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k;
string s;
const int inf = 0x3f3f3f3f;
int main(){
    while(cin >> n >> k >> s) {
        vector<int> cnt(26, 0);
        for(int c: s){
            cnt[c-'A']++;
        }
        int res=inf;
        for (int i=0;i<k;i++){
            res=min(res,cnt[i]);
        }
        printf("%I64d\n",1LL*res*k);
    }




    return 0;
}