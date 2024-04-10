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
int n,n0,n1;
string s;
int cnt[26];
int main(){
    cin>>n>>s;
    for (int i=0;i<s.size();i++)cnt[s[i]-'a']++;
    n0=cnt[25];
    cnt[4]-=n0;
	n1=cnt[4];
	for (int i=1;i<=n1;i++)putchar('1'),putchar(' ');
	for (int i=1;i<=n0;i++)putchar('0'),putchar(' ');
	puts("");
    return 0;
}