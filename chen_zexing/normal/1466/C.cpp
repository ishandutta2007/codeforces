#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        for(int i=l;i>=1;i--) s[i]=s[i-1];
        int ans=0;
        for(int i=2;i<=l;i++){
            if(s[i]==s[i-1]) ans++,s[i]='#';
            else if(i>2&&s[i]==s[i-2]) ans++,s[i]='#';
        }
        cout<<ans<<endl;
    }
    return 0;
}