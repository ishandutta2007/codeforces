#include <bits/stdc++.h>
using namespace std;
const int A=6;
int lq[1<<A], mq[1<<A], yk[1<<A];
int cha(int le, int mask, int add)
{
    for(int a=0; a<(1<<A); a++)
    {
        if(a&(1<<le)) lq[a]+=add;
        if(a&mask) mq[a]+=add;
    }
}
bool check()
{
    for(int a=0; a<(1<<A); a++)
    {
        if(lq[a]>mq[a]) return false;
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), m;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        ar[a]=(1<<A)-1;
        cha(s[a]-'a', ar[a], 1);
    }
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int p;
        scanf("%d", &p);
        p--;
        cha(s[p]-'a', ar[p], -1);
        ar[p]=0;
        string t;
        cin>>t;
        for(int b=0; b<t.size(); b++) ar[p]+=(1<<(t[b]-'a'));
        cha(s[p]-'a', ar[p], 1);
    }
    if(check())
    {
        for(int a=0; a<n; a++)
        {
            int mask=ar[a];
            for(yk[mask]; ; yk[mask]++)
            {
                int le=yk[mask];
                if((mask&(1<<le)) and lq[1<<le])
                {
                    cha(le, mask, -1);
                    if(check())
                    {
                        char sy=le+'a';
                        cout<<sy;
                        break;
                    }
                    else cha(le, mask, 1);
                }
            }
        }
    }
    else cout<<"Impossible";
}