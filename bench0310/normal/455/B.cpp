#include <bits/stdc++.h>

using namespace std;

const int N=100005;
char s[N];
vector<vector<int>> trie(N,vector<int>(26,0));
int now=2;
vector<int> v[N];

void add()
{
    int n=strlen(s);
    int idx=1;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(trie[idx][c-'a']==0)
        {
            v[idx].push_back(now);
            trie[idx][c-'a']=now++;
        }
        idx=trie[idx][c-'a'];
    }
}

bool win(int a,int p=-1)
{
    bool res=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        if(win(to,a)==0) res=1;
    }
    return res;
}

bool lose(int a,int p=-1)
{
    bool res=0;
    int cnt=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        if(lose(to,a)==0) res=1;
        cnt++;
    }
    if(cnt==0) res=1;
    return res;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    while(n--)
    {
        scanf("%s",s);
        add();
    }
    bool w=win(1);
    bool l=lose(1);
    if(w==1&&l==1) printf("First\n");
    else if(w==1)
    {
        if((k%2)==0) printf("Second\n");
        else printf("First\n");
    }
    else printf("Second\n");
    return 0;
}