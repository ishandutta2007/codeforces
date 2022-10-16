#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
char s[1000005];
int n,cnt[26];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++){
    	int fg=0;
    	for (int j=0;j<s[i]-'a';j++)
    		if (cnt[j]>0)fg=1;
    	if (fg==1)puts("Ann");
    	else puts("Mike");
    	cnt[s[i]-'a']++;
	}
    return 0;
}