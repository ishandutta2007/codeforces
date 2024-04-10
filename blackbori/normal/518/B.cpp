#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

string s,t;

int I[60],I2[60];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    cin >> s >> t;
    int i;
    for(i=0; i<t.size(); i++){
        if(t[i] >= 'a' && t[i] <= 'z'){
            I[t[i]-'a']++;
        }else{
            I[t[i]-'A'+26]++;
        }
    }
    for(i=0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            I2[s[i]-'a']++;
        }else{
            I2[s[i]-'A'+26]++;
        }
    }

    int ans=0,ans2=0,k;
    for(i=0; i<52; i++){
        k = min(I[i],I2[i]);
        I[i] -= k; I2[i] -= k; ans += k;
    }
    for(i=0; i<26; i++){
        ans2 += min(I[i],I2[i+26]) + min(I[i+26],I2[i]);
    }

    printf("%d %d\n",ans,ans2);

    return 0;
}