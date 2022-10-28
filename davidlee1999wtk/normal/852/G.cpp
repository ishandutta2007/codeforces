#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define N 5000005
using namespace std;
typedef long long LL;
#define debug(x) cerr<<#x<<"="<<x<<endl
string str;
int ch[N][7], tot, ed[N];
void Insert()
{
    int x = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (!ch[x][str[i]])
        {
            ch[x][str[i]] = ++tot;
        }
        x = ch[x][str[i]];
        if (i == str.size() - 1)
            ed[x]++;
    }
}
map<string, int> mp;
int ans;
void Query()
{
    int x = 0;
    if (mp[str])
        return;
    mp[str] = 1;
    //debug(str);
    for (int i = 0; i < str.size(); i++)
    {
        if (!ch[x][str[i]])
        {
            break;
        }
        x = ch[x][str[i]];
        if (i == str.size()-1)
            ans+=ed[x];
    }
}

void dfs(vector<string> &q, int dep, string now_str)
{
    now_str = now_str + q[dep];
    if (dep == q.size() - 1)
    {
        str = now_str;
        Query();
        return;
    }
    dfs(q, dep + 1, now_str);
    string tmp = "a";
    for (char c = 'a'; c <= 'e'; c++)
    {
        tmp[0] = c;
        dfs(q, dep + 1, now_str + tmp);
    }
}

int main()
{
    int n, m,i,last,j;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> str;
        Insert();
    }
    string qu;
    for (i = 1; i <= m; i++)
    {
        mp.clear();
        cin >> qu;
        vector<string> q;
        last = 0;
        for (j = 0; j < qu.size(); j++)
        {
            if (qu[j] == '?')
            {
                q.push_back(qu.substr(last, j - last));
                last = j + 1;
            }
        }
        //if(last < qu.size()))
        q.push_back(qu.substr(last, j - last));
        //for (auto it : q)
            //debug(it);
        ans = 0;
        dfs(q,0,"");
        printf("%d\n", ans);
    }
    return 0;
}
/*
3 1
abc
aec
ac
ab?
*/