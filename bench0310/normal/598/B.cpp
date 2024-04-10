#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[10001];
    scanf("%s",s);
    int n=strlen(s);
    int m;
    scanf("%d",&m);
    vector<int> l(m),r(m),k(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&k[i]);
        l[i]--;
        r[i]--;
    }
    char res[n+1];
    res[n]='\0';
    for(int o=0;o<n;o++)
    {
        int idx=o;
        for(int i=0;i<m;i++) if(l[i]<=idx&&idx<=r[i]) idx=l[i]+(idx-l[i]+k[i])%(r[i]-l[i]+1);
        res[idx]=s[o];
    }
    printf("%s\n",res);
    return 0;
}