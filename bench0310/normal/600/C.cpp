#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[200001];
    scanf("%s",s);
    int n=strlen(s);
    vector<int> v(26,0);
    for(int i=0;i<n;i++) v[s[i]-'a']++;
    int l=0,r=25;
    while(l<r)
    {
        if((v[l]&1)&&(v[r]&1))
        {
            v[l]++;
            v[r]--;
        }
        else if(v[l]&1) r--;
        else if(v[r]&1) l++;
        else
        {
            l++;
            r--;
        }
    }
    char res[n+1];
    res[n]='\0';
    l=0,r=n-1;
    char odd='0';
    for(int i=0;i<26;i++) if(v[i]&1) odd=('a'+i);
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<v[i]/2;j++)
        {
            res[l++]=('a'+i);
            res[r--]=('a'+i);
        }
    }
    if(l==r) res[l]=odd;
    printf("%s\n",res);
    return 0;
}