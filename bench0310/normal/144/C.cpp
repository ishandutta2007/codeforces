#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[100001];
    char t[100001];
    scanf("%s%s",s,t);
    int n=strlen(s);
    int m=strlen(t);
    vector<int> a(26,0);
    vector<int> b(26,0);
    for(int i=0;i<m;i++) b[t[i]-'a']++;
    for(int i=0;i<min(n,m);i++) if(s[i]!='?') a[s[i]-'a']++;
    auto ok=[&]()
    {
        for(int i=0;i<26;i++) if(a[i]>b[i]) return 0;
        return 1;
    };
    int res=(ok()&&n>=m);
    for(int i=m;i<n;i++)
    {
        if(s[i-m]!='?') a[s[i-m]-'a']--;
        if(s[i]!='?') a[s[i]-'a']++;
        res+=ok();
    }
    printf("%d\n",res);
    return 0;
}