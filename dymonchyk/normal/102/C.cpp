#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <ctime>
#pragma comment(linker,"/STACK:64000000")

#define ll long long

using namespace std;

char str[100002];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int k,l=strlen(str),tot=0;
    cin >> k;
    int cnt[27]={0};
    for(int i=0;i<l;i++)
        cnt[(str[i]-'a')]++;
    vector < pair<int,char> > v;
    for(int i=0;i<26;i++)
        if (cnt[i])
        {
            v.push_back(make_pair(cnt[i],'a'+i));
            tot++;
        }
    sort(v.begin(),v.end());
    bool free[256]={0};
    for(int i=0;i<v.size();i++)
    {
        if (k>=v[i].first)
        {
            tot--;
            k-=v[i].first;
            free[v[i].second]=true;
        }
    }
    cout << tot << endl;
    for(int i=0;i<l;i++)
        if (!free[str[i]]) printf("%c",str[i]);
    printf("\n");
    return 0;
}