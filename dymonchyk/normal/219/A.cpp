#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n; char str[1002];
    cin >> n >> str;
    int l=strlen(str),cnt[27]={0};
    for(int i=0;i<l;++i) cnt[str[i]-'a']++;
    for(int i=0;i<26;++i)
        if (cnt[i]%n!=0) {
            puts("-1");
            return 0;
        }
    int pos=0;
    for(int i=0;i<26;++i) {
        while(cnt[i]) {
            for(int j=0;j<n;++j)
                str[j*(l/n)+pos]='a'+i,--cnt[i];
            ++pos;
        }
    }
    puts(str);
    return 0;
}