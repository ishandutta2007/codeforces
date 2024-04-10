#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
long long fen[2][sz];
void cha(int i, int p, int va)
{
    while(p<sz)
    {
        fen[i][p]+=va, p=p|(p+1);
    }
}
long long que(int i, int p)
{
    long long re=0;
    while(p>=0)
    {
        re+=fen[i][p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin>>n>>m;
	char s[2][n+m+1];
	scanf("%s%s%s", s[0]+m, s[1], s[1]+n);
	for(int a=0; a<m; a++) s[0][a]=s[1][a+n];
	reverse(s[1], s[1]+n+m);
	int pref[n], suf[n];
	for(int i=0; i<2; i++)
    {
        int zf[n+m], l=0, r=-1;
        zf[0]=0;
        for(int a=1; a<n+m; a++)
        {
            zf[a]=0;
            if(r>=a) zf[a]=min(zf[a-l], r-a+1);
            while(a+zf[a]<n+m)
            {
                if(s[i][zf[a]]==s[i][a+zf[a]]) zf[a]++;
                else break;
            }
            if(a+zf[a]-1>r) l=a, r=a+zf[a]-1;
            if(a>=m)
            {
                if(i==0) pref[a-m]=min(zf[a], m-1);
                else suf[n-1-(a-m)]=min(zf[a], m-1);
            }
        }
    }
    int yk=0;
    long long an=0;
    for(int a=0; a<n; a++)
    {
        while(yk<n and yk-a+1<m)
        {
            cha(0, suf[yk], 1);
            cha(1, suf[yk], suf[yk]);
            yk++;
        }

        int q=que(0, m)-que(0, m-pref[a]-1);
        long long su=que(1, m)-que(1, m-pref[a]-1);
        an+=q+(su-1ll*q*(m-pref[a]));

        cha(0, suf[a], -1);
        cha(1, suf[a], -suf[a]);
    }
    cout<<an;
}